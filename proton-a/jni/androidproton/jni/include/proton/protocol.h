/* generated */
#ifndef _PROTON_PROTOCOL_H
#define _PROTON_PROTOCOL_H 1

#define OPEN_CONTAINER_ID (0)
#define OPEN_HOSTNAME (1)
#define OPEN_MAX_FRAME_SIZE (2)
#define OPEN_CHANNEL_MAX (3)
#define OPEN_IDLE_TIME_OUT (4)
#define OPEN_OUTGOING_LOCALES (5)
#define OPEN_INCOMING_LOCALES (6)
#define OPEN_OFFERED_CAPABILITIES (7)
#define OPEN_DESIRED_CAPABILITIES (8)
#define OPEN_PROPERTIES (9)
#define BEGIN_REMOTE_CHANNEL (0)
#define BEGIN_NEXT_OUTGOING_ID (1)
#define BEGIN_INCOMING_WINDOW (2)
#define BEGIN_OUTGOING_WINDOW (3)
#define BEGIN_HANDLE_MAX (4)
#define BEGIN_OFFERED_CAPABILITIES (5)
#define BEGIN_DESIRED_CAPABILITIES (6)
#define BEGIN_PROPERTIES (7)
#define ATTACH_NAME (0)
#define ATTACH_HANDLE (1)
#define ATTACH_ROLE (2)
#define ATTACH_SND_SETTLE_MODE (3)
#define ATTACH_RCV_SETTLE_MODE (4)
#define ATTACH_SOURCE (5)
#define ATTACH_TARGET (6)
#define ATTACH_UNSETTLED (7)
#define ATTACH_INCOMPLETE_UNSETTLED (8)
#define ATTACH_INITIAL_DELIVERY_COUNT (9)
#define ATTACH_MAX_MESSAGE_SIZE (10)
#define ATTACH_OFFERED_CAPABILITIES (11)
#define ATTACH_DESIRED_CAPABILITIES (12)
#define ATTACH_PROPERTIES (13)
#define FLOW_NEXT_INCOMING_ID (0)
#define FLOW_INCOMING_WINDOW (1)
#define FLOW_NEXT_OUTGOING_ID (2)
#define FLOW_OUTGOING_WINDOW (3)
#define FLOW_HANDLE (4)
#define FLOW_DELIVERY_COUNT (5)
#define FLOW_LINK_CREDIT (6)
#define FLOW_AVAILABLE (7)
#define FLOW_DRAIN (8)
#define FLOW_ECHO (9)
#define FLOW_PROPERTIES (10)
#define TRANSFER_HANDLE (0)
#define TRANSFER_DELIVERY_ID (1)
#define TRANSFER_DELIVERY_TAG (2)
#define TRANSFER_MESSAGE_FORMAT (3)
#define TRANSFER_SETTLED (4)
#define TRANSFER_MORE (5)
#define TRANSFER_RCV_SETTLE_MODE (6)
#define TRANSFER_STATE (7)
#define TRANSFER_RESUME (8)
#define TRANSFER_ABORTED (9)
#define TRANSFER_BATCHABLE (10)
#define DISPOSITION_ROLE (0)
#define DISPOSITION_FIRST (1)
#define DISPOSITION_LAST (2)
#define DISPOSITION_SETTLED (3)
#define DISPOSITION_STATE (4)
#define DISPOSITION_BATCHABLE (5)
#define DETACH_HANDLE (0)
#define DETACH_CLOSED (1)
#define DETACH_ERROR (2)
#define END_ERROR (0)
#define CLOSE_ERROR (0)
#define ERROR_CONDITION (0)
#define ERROR_DESCRIPTION (1)
#define ERROR_INFO (2)
#define HEADER_DURABLE (0)
#define HEADER_PRIORITY (1)
#define HEADER_TTL (2)
#define HEADER_FIRST_ACQUIRER (3)
#define HEADER_DELIVERY_COUNT (4)
#define PROPERTIES_MESSAGE_ID (0)
#define PROPERTIES_USER_ID (1)
#define PROPERTIES_TO (2)
#define PROPERTIES_SUBJECT (3)
#define PROPERTIES_REPLY_TO (4)
#define PROPERTIES_CORRELATION_ID (5)
#define PROPERTIES_CONTENT_TYPE (6)
#define PROPERTIES_CONTENT_ENCODING (7)
#define PROPERTIES_ABSOLUTE_EXPIRY_TIME (8)
#define PROPERTIES_CREATION_TIME (9)
#define PROPERTIES_GROUP_ID (10)
#define PROPERTIES_GROUP_SEQUENCE (11)
#define PROPERTIES_REPLY_TO_GROUP_ID (12)
#define RECEIVED_SECTION_NUMBER (0)
#define RECEIVED_SECTION_OFFSET (1)
#define REJECTED_ERROR (0)
#define MODIFIED_DELIVERY_FAILED (0)
#define MODIFIED_UNDELIVERABLE_HERE (1)
#define MODIFIED_MESSAGE_ANNOTATIONS (2)
#define SOURCE_ADDRESS (0)
#define SOURCE_DURABLE (1)
#define SOURCE_EXPIRY_POLICY (2)
#define SOURCE_TIMEOUT (3)
#define SOURCE_DYNAMIC (4)
#define SOURCE_DYNAMIC_NODE_PROPERTIES (5)
#define SOURCE_DISTRIBUTION_MODE (6)
#define SOURCE_FILTER (7)
#define SOURCE_DEFAULT_OUTCOME (8)
#define SOURCE_OUTCOMES (9)
#define SOURCE_CAPABILITIES (10)
#define TARGET_ADDRESS (0)
#define TARGET_DURABLE (1)
#define TARGET_EXPIRY_POLICY (2)
#define TARGET_TIMEOUT (3)
#define TARGET_DYNAMIC (4)
#define TARGET_DYNAMIC_NODE_PROPERTIES (5)
#define TARGET_CAPABILITIES (6)
#define SASL_MECHANISMS_SASL_SERVER_MECHANISMS (0)
#define SASL_INIT_MECHANISM (0)
#define SASL_INIT_INITIAL_RESPONSE (1)
#define SASL_INIT_HOSTNAME (2)
#define SASL_CHALLENGE_CHALLENGE (0)
#define SASL_RESPONSE_RESPONSE (0)
#define SASL_OUTCOME_CODE (0)
#define SASL_OUTCOME_ADDITIONAL_DATA (1)
#define HEADER_DURABLE (0)
#define HEADER_PRIORITY (1)
#define HEADER_TTL (2)
#define HEADER_FIRST_ACQUIRER (3)
#define HEADER_DELIVERY_COUNT (4)
#define PROPERTIES_MESSAGE_ID (0)
#define PROPERTIES_USER_ID (1)
#define PROPERTIES_TO (2)
#define PROPERTIES_SUBJECT (3)
#define PROPERTIES_REPLY_TO (4)
#define PROPERTIES_CORRELATION_ID (5)
#define PROPERTIES_CONTENT_TYPE (6)
#define PROPERTIES_CONTENT_ENCODING (7)
#define PROPERTIES_ABSOLUTE_EXPIRY_TIME (8)
#define PROPERTIES_CREATION_TIME (9)
#define PROPERTIES_GROUP_ID (10)
#define PROPERTIES_GROUP_SEQUENCE (11)
#define PROPERTIES_REPLY_TO_GROUP_ID (12)
#define OPEN_SYM ("amqp:open:list")
#define OPEN ((uint64_t) 16)
#define BEGIN_SYM ("amqp:begin:list")
#define BEGIN ((uint64_t) 17)
#define ATTACH_SYM ("amqp:attach:list")
#define ATTACH ((uint64_t) 18)
#define FLOW_SYM ("amqp:flow:list")
#define FLOW ((uint64_t) 19)
#define TRANSFER_SYM ("amqp:transfer:list")
#define TRANSFER ((uint64_t) 20)
#define DISPOSITION_SYM ("amqp:disposition:list")
#define DISPOSITION ((uint64_t) 21)
#define DETACH_SYM ("amqp:detach:list")
#define DETACH ((uint64_t) 22)
#define END_SYM ("amqp:end:list")
#define END ((uint64_t) 23)
#define CLOSE_SYM ("amqp:close:list")
#define CLOSE ((uint64_t) 24)
#define ERROR_SYM ("amqp:error:list")
#define ERROR ((uint64_t) 29)
#define HEADER_SYM ("amqp:header:list")
#define HEADER ((uint64_t) 112)
#define PROPERTIES_SYM ("amqp:properties:list")
#define PROPERTIES ((uint64_t) 115)
#define RECEIVED_SYM ("amqp:received:list")
#define RECEIVED ((uint64_t) 35)
#define ACCEPTED_SYM ("amqp:accepted:list")
#define ACCEPTED ((uint64_t) 36)
#define REJECTED_SYM ("amqp:rejected:list")
#define REJECTED ((uint64_t) 37)
#define RELEASED_SYM ("amqp:released:list")
#define RELEASED ((uint64_t) 38)
#define MODIFIED_SYM ("amqp:modified:list")
#define MODIFIED ((uint64_t) 39)
#define SOURCE_SYM ("amqp:source:list")
#define SOURCE ((uint64_t) 40)
#define TARGET_SYM ("amqp:target:list")
#define TARGET ((uint64_t) 41)
#define DELETE_ON_CLOSE_SYM ("amqp:delete-on-close:list")
#define DELETE_ON_CLOSE ((uint64_t) 43)
#define DELETE_ON_NO_LINKS_SYM ("amqp:delete-on-no-links:list")
#define DELETE_ON_NO_LINKS ((uint64_t) 44)
#define DELETE_ON_NO_MESSAGES_SYM ("amqp:delete-on-no-messages:list")
#define DELETE_ON_NO_MESSAGES ((uint64_t) 45)
#define DELETE_ON_NO_LINKS_OR_MESSAGES_SYM ("amqp:delete-on-no-links-or-messages:list")
#define DELETE_ON_NO_LINKS_OR_MESSAGES ((uint64_t) 46)
#define SASL_MECHANISMS_SYM ("amqp:sasl-mechanisms:list")
#define SASL_MECHANISMS ((uint64_t) 64)
#define SASL_INIT_SYM ("amqp:sasl-init:list")
#define SASL_INIT ((uint64_t) 65)
#define SASL_CHALLENGE_SYM ("amqp:sasl-challenge:list")
#define SASL_CHALLENGE ((uint64_t) 66)
#define SASL_RESPONSE_SYM ("amqp:sasl-response:list")
#define SASL_RESPONSE ((uint64_t) 67)
#define SASL_OUTCOME_SYM ("amqp:sasl-outcome:list")
#define SASL_OUTCOME ((uint64_t) 68)
#define HEADER_SYM ("amqp:header:list")
#define HEADER ((uint64_t) 112)
#define DELIVERY_ANNOTATIONS_SYM ("amqp:delivery-annotations:map")
#define DELIVERY_ANNOTATIONS ((uint64_t) 113)
#define MESSAGE_ANNOTATIONS_SYM ("amqp:message-annotations:map")
#define MESSAGE_ANNOTATIONS ((uint64_t) 114)
#define PROPERTIES_SYM ("amqp:properties:list")
#define PROPERTIES ((uint64_t) 115)
#define APPLICATION_PROPERTIES_SYM ("amqp:application-properties:map")
#define APPLICATION_PROPERTIES ((uint64_t) 116)
#define DATA_SYM ("amqp:data:binary")
#define DATA ((uint64_t) 117)
#define AMQP_SEQUENCE_SYM ("amqp:amqp-sequence:list")
#define AMQP_SEQUENCE ((uint64_t) 118)
#define AMQP_VALUE_SYM ("amqp:amqp-value:*")
#define AMQP_VALUE ((uint64_t) 119)
#define FOOTER_SYM ("amqp:footer:map")
#define FOOTER ((uint64_t) 120)

typedef struct {
  const char *name;
  const char *fields[32];
} pn_fields_t;

#ifndef DEFINE_FIELDS
extern
#endif
pn_fields_t FIELDS[256]
#ifdef DEFINE_FIELDS
 = {
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {"open", {"container-id", "hostname", "max-frame-size", "channel-max", "idle-time-out", "outgoing-locales", "incoming-locales", "offered-capabilities", "desired-capabilities", "properties"}},
  {"begin", {"remote-channel", "next-outgoing-id", "incoming-window", "outgoing-window", "handle-max", "offered-capabilities", "desired-capabilities", "properties"}},
  {"attach", {"name", "handle", "role", "snd-settle-mode", "rcv-settle-mode", "source", "target", "unsettled", "incomplete-unsettled", "initial-delivery-count", "max-message-size", "offered-capabilities", "desired-capabilities", "properties"}},
  {"flow", {"next-incoming-id", "incoming-window", "next-outgoing-id", "outgoing-window", "handle", "delivery-count", "link-credit", "available", "drain", "echo", "properties"}},
  {"transfer", {"handle", "delivery-id", "delivery-tag", "message-format", "settled", "more", "rcv-settle-mode", "state", "resume", "aborted", "batchable"}},
  {"disposition", {"role", "first", "last", "settled", "state", "batchable"}},
  {"detach", {"handle", "closed", "error"}},
  {"end", {"error"}},
  {"close", {"error"}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {"error", {"condition", "description", "info"}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {"received", {"section-number", "section-offset"}},
  {"accepted", {NULL}},
  {"rejected", {"error"}},
  {"released", {NULL}},
  {"modified", {"delivery-failed", "undeliverable-here", "message-annotations"}},
  {"source", {"address", "durable", "expiry-policy", "timeout", "dynamic", "dynamic-node-properties", "distribution-mode", "filter", "default-outcome", "outcomes", "capabilities"}},
  {"target", {"address", "durable", "expiry-policy", "timeout", "dynamic", "dynamic-node-properties", "capabilities"}},
  {NULL, {NULL}},
  {"delete-on-close", {NULL}},
  {"delete-on-no-links", {NULL}},
  {"delete-on-no-messages", {NULL}},
  {"delete-on-no-links-or-messages", {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {"sasl-mechanisms", {"sasl-server-mechanisms"}},
  {"sasl-init", {"mechanism", "initial-response", "hostname"}},
  {"sasl-challenge", {"challenge"}},
  {"sasl-response", {"response"}},
  {"sasl-outcome", {"code", "additional-data"}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {"header", {"durable", "priority", "ttl", "first-acquirer", "delivery-count"}},
  {"delivery-annotations", {NULL}},
  {"message-annotations", {NULL}},
  {"properties", {"message-id", "user-id", "to", "subject", "reply-to", "correlation-id", "content-type", "content-encoding", "absolute-expiry-time", "creation-time", "group-id", "group-sequence", "reply-to-group-id"}},
  {"application-properties", {NULL}},
  {"data", {NULL}},
  {"amqp-sequence", {NULL}},
  {"amqp-value", {NULL}},
  {"footer", {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
  {NULL, {NULL}},
}
#endif
;

#endif /* protocol.h */
