
// From https://github.com/Taxilof/ipmi-server/blob/master/rmcp.h

// Ports
#define RMCP_UDP_PORT					623


// Header Offsets and Length
#define RMCP_HEADER_OFFSET_VERSION 		0x00
#define RMCP_HEADER_OFFSET_RESERVED 	0x01	 // not used
#define RMCP_HEADER_OFFSET_SEQ_NR 		0x02
#define RMCP_HEADER_OFFSET_CLASS 		0x03
#define RMCP_HEADER_LENGTH 				0x04

// Header Masks
#define RCMP_HEADER_CLASS_MASK			0b00001111	// 6: ASF, 7: IPMI, etc

// Header Values
#define RMCP_HEADER_VERSION				0x06	//
#define RMCP_HEADER_RESERVED			0x00

#define RMCP_HEADER_CLASS_ASF			0x06
#define RMCP_HEADER_CLASS_IPMI			0x07
#define RMCP_HEADER_SEQ_NOACK			0xff



// responder
#define IPMI_MSG_HEADER_RSSA        0x00  // rs_sa responder slave address
#define IPMI_MSG_HEADER_NETFN_RSLNUN    0x01  // 7:2 net_fn, 1:0 rs_lun
#define IPMI_MSG_HEADER_CHECKSUM_HEADER   0x02  // checksum header
#define IPMI_MSG_HEADER_LENGTH        0x06  // length of head, see struct ipmi_msg_out
// requester
#define IPMI_MSG_HEADER_RQSA        0x03  // rq_sa requester slave address
#define IPMI_MSG_HEADER_RQSEQ_RQLNUN    0x04  // 7:2 rq_seq, 1:0 rq_lun
#define IPMI_MSG_HEADER_CMD         0x05  // rq_cmd
#define IPMI_MSG_HEADER_CHECKSUM_DATA   0x06  // checksum data

// network functions
#define IPMI_NETFN_CHASSIS        0x00
#define IPMI_NETFN_BRIDGE       0x02
#define IPMI_NETFN_SENSOR       0x04
#define IPMI_NETFN_APP          0x06
#define IPMI_NETFN_FIRMWARE       0x08
#define IPMI_NETFN_STORAGE        0x0A
#define IPMI_NETFN_TRANSPORT      0x0C

// general ommand offsets
#define CMD_OFFSET_COMPL_CODE     0x00
// cmds application
#define IPMI_CMD_GET_DEVICE_ID      0x01  // get device ID
/*****************************************************************************/
/* IPMI command: Get Channel Authentication Capabilities
/*****************************************************************************/
#define IPMI_CMD_GET_CHAN_AUTH_CAPA   0x38
#define GCAC_CHANNEL_NUM        0x01  // Channel Number
#define GCAC_AUTH_TYPE          0x02  // Authentication Type Support
#define GCAC_AUTO_TYPE_BIT_NONE     0x01
#define GCAC_AUTO_TYPE_BIT_MD2      0x02
#define GCAC_AUTO_TYPE_BIT_MD5      0x04
#define GCAC_AUTO_TYPE_BIT_RES      0x08
#define GCAC_AUTO_TYPE_BIT_PWKEY    0x10
#define GCAC_AUTO_TYPE_BIT_OEM      0x20
#define GCAC_AUTH_STATUS        0x03  // Authentication Status


/*****************************************************************************/
/* IPMI command: Get Channel Authentication Capabilities
/*****************************************************************************/
#define IPMI_CMD_GET_SESS_CHALLENGE   0x39

#define IPMI_CMD_ACTIVE_SESS      0x3a  // Activate Session
#define IPMI_CMD_SET_SES_PRIV_LEVEL   0x3b  // Set Session Privilege Level
#define IPMI_CMD_CLOSE_SESSION      0x3c  // Close Session
// cmds storage
#define IPMI_CMD_GET_SDR_REPO_INFO    0x20  // Get SDR Repository Info
#define IPMI_CMD_RESERVE_SDR_REPO   0x22  // Reserve SDR Repository
#define IPMI_CMD_GET_SDR        0x23  // Get SDR
#define IPMI_CMD_SEND_MSG       0x34  // Send Message

// cmds sensors
#define IPMI_CMD_GET_SENSOR_READING     0x2d  // Get Sensor Reading
#define IPMI_CMD_GET_SENSOR_FACTORS     0x23  // Get Sensor Reading Factors
#define IPMI_CMD_GET_SENSOR_THRESHOLDS    0x27  // Get Sensor Thresholds
#define IPMI_CMD_GET_SENSOR_EVENT_STATUS  0x2b  // Get Sensor Event Status
#define IPMI_CMD_GET_SENSOR_EVENT_ENABLE  0x29  // Get Sensor Event Enable

// Network Function Codes
#define IPMI_NETFN_CHASSIS        0x00
#define IPMI_NETFN_BRIDGE       0x02
#define IPMI_NETFN_SENSOR       0x04
#define IPMI_NETFN_APP          0x06
#define IPMI_NETFN_FIRMWARE       0x08
#define IPMI_NETFN_STORAGE        0x0A
