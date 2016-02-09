
(cl:in-package :asdf)

(defsystem "ceres_amu-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "AMU" :depends-on ("_package_AMU"))
    (:file "_package_AMU" :depends-on ("_package"))
  ))