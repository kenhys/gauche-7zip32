;;;
;;; Test gauche_7zip32
;;;

(use gauche.test)
(use gauche.interactive)

(test-start "os.windows.7zip32")
(use os.windows)
(use os.windows.7zip32)
(test-module 'os.windows.7zip32)

;; The following is a dummy test code.
;; Replace it for your tests.
(test* "test-gauche_7zip32" "gauche_7zip32 is working"
       (test-gauche_7zip32))

(d (apropos 'zip))
;; epilogue
(test-end)





