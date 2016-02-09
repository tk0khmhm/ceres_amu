; Auto-generated. Do not edit!


(cl:in-package ceres_amu-msg)


;//! \htmlinclude AMU.msg.html

(cl:defclass <AMU> (roslisp-msg-protocol:ros-message)
  ((xaccel
    :reader xaccel
    :initarg :xaccel
    :type cl:float
    :initform 0.0)
   (yaccel
    :reader yaccel
    :initarg :yaccel
    :type cl:float
    :initform 0.0)
   (zaccel
    :reader zaccel
    :initarg :zaccel
    :type cl:float
    :initform 0.0)
   (droll
    :reader droll
    :initarg :droll
    :type cl:float
    :initform 0.0)
   (dpitch
    :reader dpitch
    :initarg :dpitch
    :type cl:float
    :initform 0.0)
   (dyaw
    :reader dyaw
    :initarg :dyaw
    :type cl:float
    :initform 0.0)
   (roll
    :reader roll
    :initarg :roll
    :type cl:float
    :initform 0.0)
   (pitch
    :reader pitch
    :initarg :pitch
    :type cl:float
    :initform 0.0)
   (yaw
    :reader yaw
    :initarg :yaw
    :type cl:float
    :initform 0.0)
   (status
    :reader status
    :initarg :status
    :type cl:float
    :initform 0.0))
)

(cl:defclass AMU (<AMU>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <AMU>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'AMU)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ceres_amu-msg:<AMU> is deprecated: use ceres_amu-msg:AMU instead.")))

(cl:ensure-generic-function 'xaccel-val :lambda-list '(m))
(cl:defmethod xaccel-val ((m <AMU>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ceres_amu-msg:xaccel-val is deprecated.  Use ceres_amu-msg:xaccel instead.")
  (xaccel m))

(cl:ensure-generic-function 'yaccel-val :lambda-list '(m))
(cl:defmethod yaccel-val ((m <AMU>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ceres_amu-msg:yaccel-val is deprecated.  Use ceres_amu-msg:yaccel instead.")
  (yaccel m))

(cl:ensure-generic-function 'zaccel-val :lambda-list '(m))
(cl:defmethod zaccel-val ((m <AMU>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ceres_amu-msg:zaccel-val is deprecated.  Use ceres_amu-msg:zaccel instead.")
  (zaccel m))

(cl:ensure-generic-function 'droll-val :lambda-list '(m))
(cl:defmethod droll-val ((m <AMU>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ceres_amu-msg:droll-val is deprecated.  Use ceres_amu-msg:droll instead.")
  (droll m))

(cl:ensure-generic-function 'dpitch-val :lambda-list '(m))
(cl:defmethod dpitch-val ((m <AMU>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ceres_amu-msg:dpitch-val is deprecated.  Use ceres_amu-msg:dpitch instead.")
  (dpitch m))

(cl:ensure-generic-function 'dyaw-val :lambda-list '(m))
(cl:defmethod dyaw-val ((m <AMU>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ceres_amu-msg:dyaw-val is deprecated.  Use ceres_amu-msg:dyaw instead.")
  (dyaw m))

(cl:ensure-generic-function 'roll-val :lambda-list '(m))
(cl:defmethod roll-val ((m <AMU>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ceres_amu-msg:roll-val is deprecated.  Use ceres_amu-msg:roll instead.")
  (roll m))

(cl:ensure-generic-function 'pitch-val :lambda-list '(m))
(cl:defmethod pitch-val ((m <AMU>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ceres_amu-msg:pitch-val is deprecated.  Use ceres_amu-msg:pitch instead.")
  (pitch m))

(cl:ensure-generic-function 'yaw-val :lambda-list '(m))
(cl:defmethod yaw-val ((m <AMU>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ceres_amu-msg:yaw-val is deprecated.  Use ceres_amu-msg:yaw instead.")
  (yaw m))

(cl:ensure-generic-function 'status-val :lambda-list '(m))
(cl:defmethod status-val ((m <AMU>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ceres_amu-msg:status-val is deprecated.  Use ceres_amu-msg:status instead.")
  (status m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <AMU>) ostream)
  "Serializes a message object of type '<AMU>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'xaccel))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'yaccel))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'zaccel))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'droll))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'dpitch))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'dyaw))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'roll))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'pitch))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'yaw))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'status))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <AMU>) istream)
  "Deserializes a message object of type '<AMU>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'xaccel) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'yaccel) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'zaccel) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'droll) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'dpitch) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'dyaw) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'roll) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'pitch) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'yaw) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'status) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<AMU>)))
  "Returns string type for a message object of type '<AMU>"
  "ceres_amu/AMU")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'AMU)))
  "Returns string type for a message object of type 'AMU"
  "ceres_amu/AMU")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<AMU>)))
  "Returns md5sum for a message object of type '<AMU>"
  "dbdcdf66fe0e5834bd3a982cef95bb82")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'AMU)))
  "Returns md5sum for a message object of type 'AMU"
  "dbdcdf66fe0e5834bd3a982cef95bb82")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<AMU>)))
  "Returns full string definition for message of type '<AMU>"
  (cl:format cl:nil "float32 xaccel # G ~%float32 yaccel~%float32 zaccel~%~%float32 droll  # deg/sec~%float32 dpitch~%float32 dyaw~%~%float32 roll   # deg~%float32 pitch~%float32 yaw~%~%float32 status~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'AMU)))
  "Returns full string definition for message of type 'AMU"
  (cl:format cl:nil "float32 xaccel # G ~%float32 yaccel~%float32 zaccel~%~%float32 droll  # deg/sec~%float32 dpitch~%float32 dyaw~%~%float32 roll   # deg~%float32 pitch~%float32 yaw~%~%float32 status~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <AMU>))
  (cl:+ 0
     4
     4
     4
     4
     4
     4
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <AMU>))
  "Converts a ROS message object to a list"
  (cl:list 'AMU
    (cl:cons ':xaccel (xaccel msg))
    (cl:cons ':yaccel (yaccel msg))
    (cl:cons ':zaccel (zaccel msg))
    (cl:cons ':droll (droll msg))
    (cl:cons ':dpitch (dpitch msg))
    (cl:cons ':dyaw (dyaw msg))
    (cl:cons ':roll (roll msg))
    (cl:cons ':pitch (pitch msg))
    (cl:cons ':yaw (yaw msg))
    (cl:cons ':status (status msg))
))
