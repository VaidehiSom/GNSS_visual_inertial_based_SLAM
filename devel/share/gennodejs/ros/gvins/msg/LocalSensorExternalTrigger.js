// Auto-generated. Do not edit!

// (in-package gvins.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class LocalSensorExternalTrigger {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.trigger_id = null;
      this.event_id = null;
      this.timestamp_host = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('trigger_id')) {
        this.trigger_id = initObj.trigger_id
      }
      else {
        this.trigger_id = 0;
      }
      if (initObj.hasOwnProperty('event_id')) {
        this.event_id = initObj.event_id
      }
      else {
        this.event_id = 0;
      }
      if (initObj.hasOwnProperty('timestamp_host')) {
        this.timestamp_host = initObj.timestamp_host
      }
      else {
        this.timestamp_host = {secs: 0, nsecs: 0};
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type LocalSensorExternalTrigger
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [trigger_id]
    bufferOffset = _serializer.uint32(obj.trigger_id, buffer, bufferOffset);
    // Serialize message field [event_id]
    bufferOffset = _serializer.uint32(obj.event_id, buffer, bufferOffset);
    // Serialize message field [timestamp_host]
    bufferOffset = _serializer.time(obj.timestamp_host, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type LocalSensorExternalTrigger
    let len;
    let data = new LocalSensorExternalTrigger(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [trigger_id]
    data.trigger_id = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [event_id]
    data.event_id = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [timestamp_host]
    data.timestamp_host = _deserializer.time(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 16;
  }

  static datatype() {
    // Returns string type for a message object
    return 'gvins/LocalSensorExternalTrigger';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'a5f284fbc0b54d0c397033867d8565f1';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # This message contains essential time information of the 
    # local sensor (visual/inertial sensor) when get triggered
    Header header   # local timestamp of the trigger
    uint32                 trigger_id
    uint32                 event_id
    time                   timestamp_host       # corresponding timestamp of the Host PC, not used in GVINS
    ================================================================================
    MSG: std_msgs/Header
    # Standard metadata for higher-level stamped data types.
    # This is generally used to communicate timestamped data 
    # in a particular coordinate frame.
    # 
    # sequence ID: consecutively increasing ID 
    uint32 seq
    #Two-integer timestamp that is expressed as:
    # * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
    # * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
    # time-handling sugar is provided by the client library
    time stamp
    #Frame this data is associated with
    string frame_id
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new LocalSensorExternalTrigger(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.trigger_id !== undefined) {
      resolved.trigger_id = msg.trigger_id;
    }
    else {
      resolved.trigger_id = 0
    }

    if (msg.event_id !== undefined) {
      resolved.event_id = msg.event_id;
    }
    else {
      resolved.event_id = 0
    }

    if (msg.timestamp_host !== undefined) {
      resolved.timestamp_host = msg.timestamp_host;
    }
    else {
      resolved.timestamp_host = {secs: 0, nsecs: 0}
    }

    return resolved;
    }
};

module.exports = LocalSensorExternalTrigger;
