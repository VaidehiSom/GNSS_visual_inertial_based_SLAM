; Auto-generated. Do not edit!


(cl:in-package gvins-msg)


;//! \htmlinclude LocalSensorExternalTrigger.msg.html

(cl:defclass <LocalSensorExternalTrigger> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (trigger_id
    :reader trigger_id
    :initarg :trigger_id
    :type cl:integer
    :initform 0)
   (event_id
    :reader event_id
    :initarg :event_id
    :type cl:integer
    :initform 0)
   (timestamp_host
    :reader timestamp_host
    :initarg :timestamp_host
    :type cl:real
    :initform 0))
)

(cl:defclass LocalSensorExternalTrigger (<LocalSensorExternalTrigger>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <LocalSensorExternalTrigger>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'LocalSensorExternalTrigger)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name gvins-msg:<LocalSensorExternalTrigger> is deprecated: use gvins-msg:LocalSensorExternalTrigger instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <LocalSensorExternalTrigger>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gvins-msg:header-val is deprecated.  Use gvins-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'trigger_id-val :lambda-list '(m))
(cl:defmethod trigger_id-val ((m <LocalSensorExternalTrigger>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gvins-msg:trigger_id-val is deprecated.  Use gvins-msg:trigger_id instead.")
  (trigger_id m))

(cl:ensure-generic-function 'event_id-val :lambda-list '(m))
(cl:defmethod event_id-val ((m <LocalSensorExternalTrigger>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gvins-msg:event_id-val is deprecated.  Use gvins-msg:event_id instead.")
  (event_id m))

(cl:ensure-generic-function 'timestamp_host-val :lambda-list '(m))
(cl:defmethod timestamp_host-val ((m <LocalSensorExternalTrigger>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gvins-msg:timestamp_host-val is deprecated.  Use gvins-msg:timestamp_host instead.")
  (timestamp_host m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <LocalSensorExternalTrigger>) ostream)
  "Serializes a message object of type '<LocalSensorExternalTrigger>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'trigger_id)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'trigger_id)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'trigger_id)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'trigger_id)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'event_id)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'event_id)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'event_id)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'event_id)) ostream)
  (cl:let ((__sec (cl:floor (cl:slot-value msg 'timestamp_host)))
        (__nsec (cl:round (cl:* 1e9 (cl:- (cl:slot-value msg 'timestamp_host) (cl:floor (cl:slot-value msg 'timestamp_host)))))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 0) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __nsec) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <LocalSensorExternalTrigger>) istream)
  "Deserializes a message object of type '<LocalSensorExternalTrigger>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'trigger_id)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'trigger_id)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'trigger_id)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'trigger_id)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'event_id)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'event_id)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'event_id)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'event_id)) (cl:read-byte istream))
    (cl:let ((__sec 0) (__nsec 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 0) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __nsec) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'timestamp_host) (cl:+ (cl:coerce __sec 'cl:double-float) (cl:/ __nsec 1e9))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<LocalSensorExternalTrigger>)))
  "Returns string type for a message object of type '<LocalSensorExternalTrigger>"
  "gvins/LocalSensorExternalTrigger")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'LocalSensorExternalTrigger)))
  "Returns string type for a message object of type 'LocalSensorExternalTrigger"
  "gvins/LocalSensorExternalTrigger")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<LocalSensorExternalTrigger>)))
  "Returns md5sum for a message object of type '<LocalSensorExternalTrigger>"
  "a5f284fbc0b54d0c397033867d8565f1")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'LocalSensorExternalTrigger)))
  "Returns md5sum for a message object of type 'LocalSensorExternalTrigger"
  "a5f284fbc0b54d0c397033867d8565f1")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<LocalSensorExternalTrigger>)))
  "Returns full string definition for message of type '<LocalSensorExternalTrigger>"
  (cl:format cl:nil "# This message contains essential time information of the ~%# local sensor (visual/inertial sensor) when get triggered~%Header header   # local timestamp of the trigger~%uint32                 trigger_id~%uint32                 event_id~%time                   timestamp_host       # corresponding timestamp of the Host PC, not used in GVINS~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'LocalSensorExternalTrigger)))
  "Returns full string definition for message of type 'LocalSensorExternalTrigger"
  (cl:format cl:nil "# This message contains essential time information of the ~%# local sensor (visual/inertial sensor) when get triggered~%Header header   # local timestamp of the trigger~%uint32                 trigger_id~%uint32                 event_id~%time                   timestamp_host       # corresponding timestamp of the Host PC, not used in GVINS~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <LocalSensorExternalTrigger>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4
     4
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <LocalSensorExternalTrigger>))
  "Converts a ROS message object to a list"
  (cl:list 'LocalSensorExternalTrigger
    (cl:cons ':header (header msg))
    (cl:cons ':trigger_id (trigger_id msg))
    (cl:cons ':event_id (event_id msg))
    (cl:cons ':timestamp_host (timestamp_host msg))
))
