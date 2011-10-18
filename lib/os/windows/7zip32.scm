;;;
;;; Test gauche_7zip32
;;;

(define-module os.windows.7zip32
  (extend os.windows.7zip32.alias)
  (export-all)
  )
(select-module os.windows.7zip32)
(dynamic-load "gauche_7zip32")
