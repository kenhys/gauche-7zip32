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

(define zip (seven-zip-create))
(d zip)
(d (seven-zip-get-version zip))
(d (seven-zip zip "x \"passwd.7z\" -aoa -p\"test\" -hide -o\"test\" -r"))


;; epilogue
(test-end)





