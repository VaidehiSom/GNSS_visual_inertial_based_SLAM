;; Auto-generated. Do not edit!


(when (boundp 'gvins::LocalSensorExternalTrigger)
  (if (not (find-package "GVINS"))
    (make-package "GVINS"))
  (shadow 'LocalSensorExternalTrigger (find-package "GVINS")))
(unless (find-package "GVINS::LOCALSENSOREXTERNALTRIGGER")
  (make-package "GVINS::LOCALSENSOREXTERNALTRIGGER"))

(in-package "ROS")
;;//! \htmlinclude LocalSensorExternalTrigger.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass gvins::LocalSensorExternalTrigger
  :super ros::object
  :slots (_header _trigger_id _event_id _timestamp_host ))

(defmethod gvins::LocalSensorExternalTrigger
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:trigger_id __trigger_id) 0)
    ((:event_id __event_id) 0)
    ((:timestamp_host __timestamp_host) (instance ros::time :init))
    )
   (send-super :init)
   (setq _header __header)
   (setq _trigger_id (round __trigger_id))
   (setq _event_id (round __event_id))
   (setq _timestamp_host __timestamp_host)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:trigger_id
   (&optional __trigger_id)
   (if __trigger_id (setq _trigger_id __trigger_id)) _trigger_id)
  (:event_id
   (&optional __event_id)
   (if __event_id (setq _event_id __event_id)) _event_id)
  (:timestamp_host
   (&optional __timestamp_host)
   (if __timestamp_host (setq _timestamp_host __timestamp_host)) _timestamp_host)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; uint32 _trigger_id
    4
    ;; uint32 _event_id
    4
    ;; time _timestamp_host
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; uint32 _trigger_id
       (write-long _trigger_id s)
     ;; uint32 _event_id
       (write-long _event_id s)
     ;; time _timestamp_host
       (write-long (send _timestamp_host :sec) s) (write-long (send _timestamp_host :nsec) s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; uint32 _trigger_id
     (setq _trigger_id (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32 _event_id
     (setq _event_id (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; time _timestamp_host
     (send _timestamp_host :sec (sys::peek buf ptr- :integer)) (incf ptr- 4)  (send _timestamp_host :nsec (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get gvins::LocalSensorExternalTrigger :md5sum-) "a5f284fbc0b54d0c397033867d8565f1")
(setf (get gvins::LocalSensorExternalTrigger :datatype-) "gvins/LocalSensorExternalTrigger")
(setf (get gvins::LocalSensorExternalTrigger :definition-)
      "# This message contains essential time information of the 
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

")



(provide :gvins/LocalSensorExternalTrigger "a5f284fbc0b54d0c397033867d8565f1")


