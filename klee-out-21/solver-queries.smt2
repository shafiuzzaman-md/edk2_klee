; Query 0 -- Type: InitialValues, Instructions: 13448
; This file conforms to SMTLIBv2 and was generated by KLEE
(set-logic QF_AUFBV )
; Array declarations
; Constraints
; Constraints and QueryExpr
(assert
        true
)
(check-sat)
(exit)
;   OK -- Elapsed: 4.323128e-03s
;   Solvable: true

; Query 1 -- Type: InitialValues, Instructions: 13448
; This file conforms to SMTLIBv2 and was generated by KLEE
(set-option :produce-models true)
(set-logic QF_AUFBV )
; Array declarations
(declare-fun CommBufferSize () (Array (_ BitVec 32) (_ BitVec 8) ) )
; Constraints
; Constraints and QueryExpr
(assert
        (= 
           false
           (bvult 
                  (concat 
                          (select 
                                  CommBufferSize
                                  (_ bv7 32)
                          )
                          (concat 
                                  (select 
                                          CommBufferSize
                                          (_ bv6 32)
                                  )
                                  (concat 
                                          (select 
                                                  CommBufferSize
                                                  (_ bv5 32)
                                          )
                                          (concat 
                                                  (select 
                                                          CommBufferSize
                                                          (_ bv4 32)
                                                  )
                                                  (concat 
                                                          (select 
                                                                  CommBufferSize
                                                                  (_ bv3 32)
                                                          )
                                                          (concat 
                                                                  (select 
                                                                          CommBufferSize
                                                                          (_ bv2 32)
                                                                  )
                                                                  (concat 
                                                                          (select 
                                                                                  CommBufferSize
                                                                                  (_ bv1 32)
                                                                          )
                                                                          (select 
                                                                                  CommBufferSize
                                                                                  (_ bv0 32)
                                                                          )
                                                                  )
                                                          )
                                                  )
                                          )
                                  )
                          )
                  )
                  (_ bv16 64)
           )
        )
)
(check-sat)
(get-value ( (select CommBufferSize (_ bv0 32) ) ) )
(get-value ( (select CommBufferSize (_ bv1 32) ) ) )
(get-value ( (select CommBufferSize (_ bv2 32) ) ) )
(get-value ( (select CommBufferSize (_ bv3 32) ) ) )
(get-value ( (select CommBufferSize (_ bv4 32) ) ) )
(get-value ( (select CommBufferSize (_ bv5 32) ) ) )
(get-value ( (select CommBufferSize (_ bv6 32) ) ) )
(get-value ( (select CommBufferSize (_ bv7 32) ) ) )
(exit)
;   OK -- Elapsed: 4.151314e-03s
;   Solvable: true
;     CommBufferSize = [16,0,0,0,0,0,0,0]

; Query 2 -- Type: InitialValues, Instructions: 13485
; This file conforms to SMTLIBv2 and was generated by KLEE
(set-option :produce-models true)
(set-logic QF_AUFBV )
; Array declarations
(declare-fun CommBuffer->Command () (Array (_ BitVec 32) (_ BitVec 8) ) )
; Constraints
; Constraints and QueryExpr
(assert
        (= 
           false
           (= 
              (_ bv0 32)
              (concat 
                      (select 
                              CommBuffer->Command
                              (_ bv3 32)
                      )
                      (concat 
                              (select 
                                      CommBuffer->Command
                                      (_ bv2 32)
                              )
                              (concat 
                                      (select 
                                              CommBuffer->Command
                                              (_ bv1 32)
                                      )
                                      (select 
                                              CommBuffer->Command
                                              (_ bv0 32)
                                      )
                              )
                      )
              )
           )
        )
)
(check-sat)
(get-value ( (select CommBuffer->Command (_ bv0 32) ) ) )
(get-value ( (select CommBuffer->Command (_ bv1 32) ) ) )
(get-value ( (select CommBuffer->Command (_ bv2 32) ) ) )
(get-value ( (select CommBuffer->Command (_ bv3 32) ) ) )
(exit)
;   OK -- Elapsed: 4.267390e-03s
;   Solvable: true
;     CommBuffer->Command = [0,0,255,0]

; Query 3 -- Type: InitialValues, Instructions: 13485
; This file conforms to SMTLIBv2 and was generated by KLEE
(set-option :produce-models true)
(set-logic QF_AUFBV )
; Array declarations
(declare-fun CommBuffer->Command () (Array (_ BitVec 32) (_ BitVec 8) ) )
; Constraints
; Constraints and QueryExpr
(assert
        (= 
           (_ bv1 32)
           (concat 
                   (select 
                           CommBuffer->Command
                           (_ bv3 32)
                   )
                   (concat 
                           (select 
                                   CommBuffer->Command
                                   (_ bv2 32)
                           )
                           (concat 
                                   (select 
                                           CommBuffer->Command
                                           (_ bv1 32)
                                   )
                                   (select 
                                           CommBuffer->Command
                                           (_ bv0 32)
                                   )
                           )
                   )
           )
        )
)
(check-sat)
(get-value ( (select CommBuffer->Command (_ bv0 32) ) ) )
(get-value ( (select CommBuffer->Command (_ bv1 32) ) ) )
(get-value ( (select CommBuffer->Command (_ bv2 32) ) ) )
(get-value ( (select CommBuffer->Command (_ bv3 32) ) ) )
(exit)
;   OK -- Elapsed: 3.792911e-03s
;   Solvable: true
;     CommBuffer->Command = [1,0,0,0]

; Query 4 -- Type: InitialValues, Instructions: 13485
; This file conforms to SMTLIBv2 and was generated by KLEE
(set-option :produce-models true)
(set-logic QF_AUFBV )
; Array declarations
(declare-fun CommBuffer->Command () (Array (_ BitVec 32) (_ BitVec 8) ) )
; Constraints
; Constraints and QueryExpr
(assert
        (= 
           (_ bv2 32)
           (concat 
                   (select 
                           CommBuffer->Command
                           (_ bv3 32)
                   )
                   (concat 
                           (select 
                                   CommBuffer->Command
                                   (_ bv2 32)
                           )
                           (concat 
                                   (select 
                                           CommBuffer->Command
                                           (_ bv1 32)
                                   )
                                   (select 
                                           CommBuffer->Command
                                           (_ bv0 32)
                                   )
                           )
                   )
           )
        )
)
(check-sat)
(get-value ( (select CommBuffer->Command (_ bv0 32) ) ) )
(get-value ( (select CommBuffer->Command (_ bv1 32) ) ) )
(get-value ( (select CommBuffer->Command (_ bv2 32) ) ) )
(get-value ( (select CommBuffer->Command (_ bv3 32) ) ) )
(exit)
;   OK -- Elapsed: 3.763698e-03s
;   Solvable: true
;     CommBuffer->Command = [2,0,0,0]

; Query 5 -- Type: InitialValues, Instructions: 13485
; This file conforms to SMTLIBv2 and was generated by KLEE
(set-option :produce-models true)
(set-logic QF_AUFBV )
; Array declarations
(declare-fun CommBuffer->Command () (Array (_ BitVec 32) (_ BitVec 8) ) )
; Constraints
; Constraints and QueryExpr
(assert
        (= 
           (_ bv3 32)
           (concat 
                   (select 
                           CommBuffer->Command
                           (_ bv3 32)
                   )
                   (concat 
                           (select 
                                   CommBuffer->Command
                                   (_ bv2 32)
                           )
                           (concat 
                                   (select 
                                           CommBuffer->Command
                                           (_ bv1 32)
                                   )
                                   (select 
                                           CommBuffer->Command
                                           (_ bv0 32)
                                   )
                           )
                   )
           )
        )
)
(check-sat)
(get-value ( (select CommBuffer->Command (_ bv0 32) ) ) )
(get-value ( (select CommBuffer->Command (_ bv1 32) ) ) )
(get-value ( (select CommBuffer->Command (_ bv2 32) ) ) )
(get-value ( (select CommBuffer->Command (_ bv3 32) ) ) )
(exit)
;   OK -- Elapsed: 3.738051e-03s
;   Solvable: true
;     CommBuffer->Command = [3,0,0,0]

; Query 6 -- Type: InitialValues, Instructions: 13485
; This file conforms to SMTLIBv2 and was generated by KLEE
(set-option :produce-models true)
(set-logic QF_AUFBV )
; Array declarations
(declare-fun CommBuffer->Command () (Array (_ BitVec 32) (_ BitVec 8) ) )
; Constraints
; Constraints and QueryExpr
(assert
        (= 
           (_ bv4 32)
           (concat 
                   (select 
                           CommBuffer->Command
                           (_ bv3 32)
                   )
                   (concat 
                           (select 
                                   CommBuffer->Command
                                   (_ bv2 32)
                           )
                           (concat 
                                   (select 
                                           CommBuffer->Command
                                           (_ bv1 32)
                                   )
                                   (select 
                                           CommBuffer->Command
                                           (_ bv0 32)
                                   )
                           )
                   )
           )
        )
)
(check-sat)
(get-value ( (select CommBuffer->Command (_ bv0 32) ) ) )
(get-value ( (select CommBuffer->Command (_ bv1 32) ) ) )
(get-value ( (select CommBuffer->Command (_ bv2 32) ) ) )
(get-value ( (select CommBuffer->Command (_ bv3 32) ) ) )
(exit)
;   OK -- Elapsed: 4.149292e-03s
;   Solvable: true
;     CommBuffer->Command = [4,0,0,0]

; Query 7 -- Type: InitialValues, Instructions: 13485
; This file conforms to SMTLIBv2 and was generated by KLEE
(set-option :produce-models true)
(set-logic QF_AUFBV )
; Array declarations
(declare-fun CommBuffer->Command () (Array (_ BitVec 32) (_ BitVec 8) ) )
; Constraints
; Constraints and QueryExpr
(assert
        (= 
           (_ bv5 32)
           (concat 
                   (select 
                           CommBuffer->Command
                           (_ bv3 32)
                   )
                   (concat 
                           (select 
                                   CommBuffer->Command
                                   (_ bv2 32)
                           )
                           (concat 
                                   (select 
                                           CommBuffer->Command
                                           (_ bv1 32)
                                   )
                                   (select 
                                           CommBuffer->Command
                                           (_ bv0 32)
                                   )
                           )
                   )
           )
        )
)
(check-sat)
(get-value ( (select CommBuffer->Command (_ bv0 32) ) ) )
(get-value ( (select CommBuffer->Command (_ bv1 32) ) ) )
(get-value ( (select CommBuffer->Command (_ bv2 32) ) ) )
(get-value ( (select CommBuffer->Command (_ bv3 32) ) ) )
(exit)
;   OK -- Elapsed: 3.860098e-03s
;   Solvable: true
;     CommBuffer->Command = [5,0,0,0]

; Query 8 -- Type: InitialValues, Instructions: 13496
; This file conforms to SMTLIBv2 and was generated by KLEE
(set-option :produce-models true)
(set-logic QF_AUFBV )
; Array declarations
(declare-fun CommBufferSize () (Array (_ BitVec 32) (_ BitVec 8) ) )
; Constraints
; Constraints and QueryExpr
(assert
        (let
            (
             (?B1
                 (concat 
                         (select 
                                 CommBufferSize
                                 (_ bv7 32)
                         )
                         (concat 
                                 (select 
                                         CommBufferSize
                                         (_ bv6 32)
                                 )
                                 (concat 
                                         (select 
                                                 CommBufferSize
                                                 (_ bv5 32)
                                         )
                                         (concat 
                                                 (select 
                                                         CommBufferSize
                                                         (_ bv4 32)
                                                 )
                                                 (concat 
                                                         (select 
                                                                 CommBufferSize
                                                                 (_ bv3 32)
                                                         )
                                                         (concat 
                                                                 (select 
                                                                         CommBufferSize
                                                                         (_ bv2 32)
                                                                 )
                                                                 (concat 
                                                                         (select 
                                                                                 CommBufferSize
                                                                                 (_ bv1 32)
                                                                         )
                                                                         (select 
                                                                                 CommBufferSize
                                                                                 (_ bv0 32)
                                                                         )
                                                                 )
                                                         )
                                                 )
                                         )
                                 )
                         )
                 )
             )
            )
            (and 
                 (= 
                    false
                    (bvult 
                           ?B1
                           (_ bv56 64)
                    )
                 )
                 (= 
                    false
                    (bvult 
                           ?B1
                           (_ bv16 64)
                    )
                 )
            )
        )
)
(check-sat)
(get-value ( (select CommBufferSize (_ bv0 32) ) ) )
(get-value ( (select CommBufferSize (_ bv1 32) ) ) )
(get-value ( (select CommBufferSize (_ bv2 32) ) ) )
(get-value ( (select CommBufferSize (_ bv3 32) ) ) )
(get-value ( (select CommBufferSize (_ bv4 32) ) ) )
(get-value ( (select CommBufferSize (_ bv5 32) ) ) )
(get-value ( (select CommBufferSize (_ bv6 32) ) ) )
(get-value ( (select CommBufferSize (_ bv7 32) ) ) )
(exit)
;   OK -- Elapsed: 6.901438e-03s
;   Solvable: true
;     CommBufferSize = [56,0,0,0,0,0,0,0]

; Query 9 -- Type: InitialValues, Instructions: 13507
; This file conforms to SMTLIBv2 and was generated by KLEE
(set-option :produce-models true)
(set-logic QF_AUFBV )
; Array declarations
(declare-fun CommBufferSize () (Array (_ BitVec 32) (_ BitVec 8) ) )
; Constraints
; Constraints and QueryExpr
(assert
        (let
            (
             (?B1
                 (concat 
                         (select 
                                 CommBufferSize
                                 (_ bv7 32)
                         )
                         (concat 
                                 (select 
                                         CommBufferSize
                                         (_ bv6 32)
                                 )
                                 (concat 
                                         (select 
                                                 CommBufferSize
                                                 (_ bv5 32)
                                         )
                                         (concat 
                                                 (select 
                                                         CommBufferSize
                                                         (_ bv4 32)
                                                 )
                                                 (concat 
                                                         (select 
                                                                 CommBufferSize
                                                                 (_ bv3 32)
                                                         )
                                                         (concat 
                                                                 (select 
                                                                         CommBufferSize
                                                                         (_ bv2 32)
                                                                 )
                                                                 (concat 
                                                                         (select 
                                                                                 CommBufferSize
                                                                                 (_ bv1 32)
                                                                         )
                                                                         (select 
                                                                                 CommBufferSize
                                                                                 (_ bv0 32)
                                                                         )
                                                                 )
                                                         )
                                                 )
                                         )
                                 )
                         )
                 )
             )
            )
            (and 
                 (= 
                    false
                    (bvult 
                           ?B1
                           (_ bv48 64)
                    )
                 )
                 (= 
                    false
                    (bvult 
                           ?B1
                           (_ bv16 64)
                    )
                 )
            )
        )
)
(check-sat)
(get-value ( (select CommBufferSize (_ bv0 32) ) ) )
(get-value ( (select CommBufferSize (_ bv1 32) ) ) )
(get-value ( (select CommBufferSize (_ bv2 32) ) ) )
(get-value ( (select CommBufferSize (_ bv3 32) ) ) )
(get-value ( (select CommBufferSize (_ bv4 32) ) ) )
(get-value ( (select CommBufferSize (_ bv5 32) ) ) )
(get-value ( (select CommBufferSize (_ bv6 32) ) ) )
(get-value ( (select CommBufferSize (_ bv7 32) ) ) )
(exit)
;   OK -- Elapsed: 5.371747e-03s
;   Solvable: true
;     CommBufferSize = [48,0,0,0,0,0,0,0]

; Query 10 -- Type: InitialValues, Instructions: 13526
; This file conforms to SMTLIBv2 and was generated by KLEE
(set-option :produce-models true)
(set-logic QF_AUFBV )
; Array declarations
(declare-fun CommBufferSize () (Array (_ BitVec 32) (_ BitVec 8) ) )
; Constraints
; Constraints and QueryExpr
(assert
        (let
            (
             (?B1
                 (concat 
                         (select 
                                 CommBufferSize
                                 (_ bv7 32)
                         )
                         (concat 
                                 (select 
                                         CommBufferSize
                                         (_ bv6 32)
                                 )
                                 (concat 
                                         (select 
                                                 CommBufferSize
                                                 (_ bv5 32)
                                         )
                                         (concat 
                                                 (select 
                                                         CommBufferSize
                                                         (_ bv4 32)
                                                 )
                                                 (concat 
                                                         (select 
                                                                 CommBufferSize
                                                                 (_ bv3 32)
                                                         )
                                                         (concat 
                                                                 (select 
                                                                         CommBufferSize
                                                                         (_ bv2 32)
                                                                 )
                                                                 (concat 
                                                                         (select 
                                                                                 CommBufferSize
                                                                                 (_ bv1 32)
                                                                         )
                                                                         (select 
                                                                                 CommBufferSize
                                                                                 (_ bv0 32)
                                                                         )
                                                                 )
                                                         )
                                                 )
                                         )
                                 )
                         )
                 )
             )
            )
            (and 
                 (= 
                    false
                    (bvult 
                           ?B1
                           (_ bv40 64)
                    )
                 )
                 (= 
                    false
                    (bvult 
                           ?B1
                           (_ bv16 64)
                    )
                 )
            )
        )
)
(check-sat)
(get-value ( (select CommBufferSize (_ bv0 32) ) ) )
(get-value ( (select CommBufferSize (_ bv1 32) ) ) )
(get-value ( (select CommBufferSize (_ bv2 32) ) ) )
(get-value ( (select CommBufferSize (_ bv3 32) ) ) )
(get-value ( (select CommBufferSize (_ bv4 32) ) ) )
(get-value ( (select CommBufferSize (_ bv5 32) ) ) )
(get-value ( (select CommBufferSize (_ bv6 32) ) ) )
(get-value ( (select CommBufferSize (_ bv7 32) ) ) )
(exit)
;   OK -- Elapsed: 5.452241e-03s
;   Solvable: true
;     CommBufferSize = [48,0,0,0,0,0,0,0]

; Query 11 -- Type: InitialValues, Instructions: 13592
; This file conforms to SMTLIBv2 and was generated by KLEE
(set-option :produce-models true)
(set-logic QF_AUFBV )
; Array declarations
(declare-fun mLocked () (Array (_ BitVec 32) (_ BitVec 8) ) )
; Constraints
; Constraints and QueryExpr
(assert
        (= 
           false
           (= 
              (_ bv0 8)
              (select 
                      mLocked
                      (_ bv0 32)
              )
           )
        )
)
(check-sat)
(get-value ( (select mLocked (_ bv0 32) ) ) )
(exit)
;   OK -- Elapsed: 4.101924e-03s
;   Solvable: true
;     mLocked = [255]

