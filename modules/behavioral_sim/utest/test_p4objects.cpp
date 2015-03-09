#include <gtest/gtest.h>

#include <sstream>
#include <string>

#include "behavioral_sim/P4Objects.h"

int pull_test_p4objects() { return 0; }

class modify_field : public ActionPrimitive<Field &, const Data &> {
  void operator ()(Field &f, const Data &d) {
    f.set(d);
  }
};

REGISTER_PRIMITIVE(modify_field);

class drop : public ActionPrimitive<> {
  void operator ()() {

  }
};

REGISTER_PRIMITIVE(drop);

class add_to_field : public ActionPrimitive<Field &, const Data &> {
  void operator ()(Field &f, const Data &d) {
    f.add(f, d);
  }
};

REGISTER_PRIMITIVE(add_to_field);

const std::string JSON_TEST_STRING =
  "{\"header_types\":[{\"name\":\"standard_metadata_t\",\"fields\":{\"ingress_port\":9,\"packet_length\":32,\"egress_spec\":9,\"egress_port\":9,\"egress_instance\":32,\"instance_type\":32,\"clone_spec\":32,\"_padding\":5}},{\"name\":\"ethernet_t\",\"fields\":{\"dstAddr\":48,\"srcAddr\":48,\"etherType\":16}},{\"name\":\"ipv4_t\",\"fields\":{\"version\":4,\"ihl\":4,\"diffserv\":8,\"totalLen\":16,\"identification\":16,\"flags\":3,\"fragOffset\":13,\"ttl\":8,\"protocol\":8,\"hdrChecksum\":16,\"srcAddr\":32,\"dstAddr\":32}},{\"name\":\"routing_metadata_t\",\"fields\":{\"nhop_ipv4\":32}}],\"headers\":[{\"name\":\"standard_metadata\",\"header_type\":\"standard_metadata_t\"},{\"name\":\"ethernet\",\"header_type\":\"ethernet_t\"},{\"name\":\"ipv4\",\"header_type\":\"ipv4_t\"},{\"name\":\"routing_metadata\",\"header_type\":\"routing_metadata_t\"}],\"parsers\":[{\"name\":\"parser\",\"init_state\":\"start\",\"parse_states\":[{\"name\":\"start\",\"extracts\":[],\"sets\":[],\"transition_key\":[],\"transitions\":[{\"value\":\"default\",\"mask\":null,\"next_state\":\"parse_ethernet\"}]},{\"name\":\"parse_ethernet\",\"extracts\":[\"ethernet\"],\"sets\":[],\"transition_key\":[[\"ethernet\",\"etherType\"]],\"transitions\":[{\"value\":\"0x800\",\"mask\":null,\"next_state\":\"parse_ipv4\"},{\"value\":\"default\",\"mask\":null,\"next_state\":null}]},{\"name\":\"parse_ipv4\",\"extracts\":[\"ipv4\"],\"sets\":[],\"transition_key\":[],\"transitions\":[{\"value\":\"default\",\"mask\":null,\"next_state\":null}]}]}],\"deparsers\":[{\"name\":\"deparser\",\"order\":[\"ethernet\",\"ipv4\"]}],\"actions\":[{\"name\":\"_drop\",\"runtime_data\":[],\"primitives\":[{\"op\":\"drop\",\"parameters\":[]}]},{\"name\":\"rewrite_mac\",\"runtime_data\":[{\"name\":\"smac\",\"bitwidth\":48}],\"primitives\":[{\"op\":\"modify_field\",\"parameters\":[{\"type\":\"field\",\"value\":[\"ethernet\",\"srcAddr\"]},{\"type\":\"runtime_data\",\"value\":0}]}]},{\"name\":\"set_nhop\",\"runtime_data\":[{\"name\":\"nhop_ipv4\",\"bitwidth\":32},{\"name\":\"port\",\"bitwidth\":9}],\"primitives\":[{\"op\":\"modify_field\",\"parameters\":[{\"type\":\"field\",\"value\":[\"routing_metadata\",\"nhop_ipv4\"]},{\"type\":\"runtime_data\",\"value\":0}]},{\"op\":\"modify_field\",\"parameters\":[{\"type\":\"field\",\"value\":[\"standard_metadata\",\"egress_spec\"]},{\"type\":\"runtime_data\",\"value\":1}]},{\"op\":\"add_to_field\",\"parameters\":[{\"type\":\"field\",\"value\":[\"ipv4\",\"ttl\"]},{\"type\":\"hexstr\",\"value\":\"-0x1\"}]}]},{\"name\":\"set_dmac\",\"runtime_data\":[{\"name\":\"dmac\",\"bitwidth\":48}],\"primitives\":[{\"op\":\"modify_field\",\"parameters\":[{\"type\":\"field\",\"value\":[\"ethernet\",\"dstAddr\"]},{\"type\":\"runtime_data\",\"value\":0}]}]}],\"pipelines\":[{\"name\":\"ingress\",\"init_table\":\"_condition_0\",\"tables\":[{\"name\":\"ipv4_lpm\",\"type\":\"lpm\",\"max_size\":1024,\"key\":[{\"match_type\":\"lpm\",\"target\":[\"ipv4\",\"dstAddr\"]}],\"actions\":[\"set_nhop\",\"_drop\"],\"next_tables\":{\"set_nhop\":\"forward\",\"_drop\":\"forward\"},\"default_action\":null},{\"name\":\"forward\",\"type\":\"exact\",\"max_size\":512,\"key\":[{\"match_type\":\"exact\",\"target\":[\"routing_metadata\",\"nhop_ipv4\"]}],\"actions\":[\"set_dmac\",\"_drop\"],\"next_tables\":{\"set_dmac\":null,\"_drop\":null},\"default_action\":null}],\"conditionals\":[{\"name\":\"_condition_0\",\"expression\":{\"type\":\"expression\",\"value\":{\"op\":\"and\",\"left\":{\"type\":\"expression\",\"value\":{\"op\":\"valid\",\"left\":null,\"right\":{\"type\":\"header\",\"value\":\"ipv4\"}}},\"right\":{\"type\":\"expression\",\"value\":{\"op\":\">\",\"left\":{\"type\":\"field\",\"value\":[\"ipv4\",\"ttl\"]},\"right\":{\"type\":\"hexstr\",\"value\":\"0x0\"}}}}},\"true_next\":\"ipv4_lpm\",\"false_next\":null}]},{\"name\":\"egress\",\"init_table\":\"send_frame\",\"tables\":[{\"name\":\"send_frame\",\"type\":\"exact\",\"max_size\":256,\"key\":[{\"match_type\":\"exact\",\"target\":[\"standard_metadata\",\"egress_port\"]}],\"actions\":[\"rewrite_mac\",\"_drop\"],\"next_tables\":{\"rewrite_mac\":null,\"_drop\":null},\"default_action\":null}],\"conditionals\":[]}]}";
  //  "{\"header_types\":[{\"name\":\"ethernet_t\",\"fields\":{\"dstAddr\":48,\"srcAddr\":48,\"ethertype\":16}},{\"name\":\"ipv4_t\",\"fields\":{\"version\":4,\"ihl\":4,\"diffserv\":8,\"len\":16,\"id\":16,\"flags\":3,\"flagOffset\":13,\"ttl\":8,\"protocol\":8,\"checksum\":16,\"srcAddr\":32,\"dstAddr\":32}},{\"name\":\"intrinsic_metadata_t\",\"fields\":{\"drop_signal\":1,\"egress_port\":9,\"_padding\":6}}],\"headers\":[{\"name\":\"ethernet\",\"header_type\":\"ethernet_t\"},{\"name\":\"ipv4\",\"header_type\":\"ipv4_t\"},{\"name\":\"intrinsic_metadata\",\"header_type\":\"intrinsic_metadata_t\"}],\"parsers\":[{\"name\":\"parser1\",\"init_state\":\"parse_ethernet\",\"parse_states\":[{\"name\":\"parse_ethernet\",\"extracts\":[\"ethernet\"],\"sets\":[],\"transition_key\":[[\"ethernet\",\"ethertype\"]],\"transitions\":[{\"value\":\"0x0800\",\"mask\":\"0xFFFF\",\"next_state\":\"parse_ipv4\"}]},{\"name\":\"parse_ipv4\",\"extracts\":[\"ipv4\"],\"sets\":[],\"transition_key\":[],\"transitions\":[]}]}],\"deparsers\":[{\"name\":\"deparser1\",\"order\":[\"ethernet\",\"ipv4\"]}],\"actions\":[{\"name\":\"drop\",\"runtime_data\":[],\"primitives\":[{\"op\":\"SetField\",\"parameters\":[{\"type\":\"field\",\"value\":[\"intrinsic_metadata\",\"drop_signal\"]},{\"type\":\"hexstr\",\"value\":\"0x1\"}]}]},{\"name\":\"forward\",\"runtime_data\":[{\"name\":\"port\",\"bitwidth\":9}],\"primitives\":[{\"op\":\"SetField\",\"parameters\":[{\"type\":\"field\",\"value\":[\"intrinsic_metadata\",\"egress_port\"]},{\"type\":\"runtime_data\",\"value\":0}]}]}],\"pipelines\":[{\"name\":\"pipeline1\",\"init_table\":\"switch\",\"tables\":[{\"name\":\"switch\",\"type\":\"exact\",\"max_size\":1024,\"key\":[{\"match_type\":\"exact\",\"target\":[\"ethernet\",\"dstAddr\"]}],\"actions\":[\"drop\",\"forward\"],\"next_tables\":{\"drop\":null,\"forward\":null},\"default_action\":null,\"ageing\":false,\"entry_counters\":false}],\"conditionals\":[]}]}";

TEST(P4Objects, LoadFromJSON) {
  std::stringstream is(JSON_TEST_STRING);
  P4Objects objects;
  objects.init_objects(is);

  ASSERT_NE(nullptr, objects.get_pipeline("ingress"));
  ASSERT_NE(nullptr, objects.get_action("_drop"));
  ASSERT_NE(nullptr, objects.get_parser("parser"));
  ASSERT_NE(nullptr, objects.get_deparser("deparser"));
  ASSERT_NE(nullptr, objects.get_exact_match_table("forward"));
  ASSERT_NE(nullptr, objects.get_lpm_table("ipv4_lpm"));
  ASSERT_NE(nullptr, objects.get_match_table("forward"));
  ASSERT_NE(nullptr, objects.get_conditional("_condition_0"));
  ASSERT_NE(nullptr, objects.get_control_node("forward"));

  objects.destroy_objects();
}