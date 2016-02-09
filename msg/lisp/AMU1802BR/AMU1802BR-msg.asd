
(in-package :asdf)

(defsystem "AMU1802BR-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils)
  :components ((:file "_package")
    (:file "AMU" :depends-on ("_package"))
    (:file "_package_AMU" :depends-on ("_package"))
    ))
