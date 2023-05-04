
(cl:in-package :asdf)

(defsystem "gvins-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "LocalSensorExternalTrigger" :depends-on ("_package_LocalSensorExternalTrigger"))
    (:file "_package_LocalSensorExternalTrigger" :depends-on ("_package"))
  ))