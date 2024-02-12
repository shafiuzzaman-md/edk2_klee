; Query 0 -- Type: InitialValues, Instructions: 13464
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
;   OK -- Elapsed: 4.838641e-03s
;   Solvable: true

; Query 1 -- Type: InitialValues, Instructions: 13464
; This file conforms to SMTLIBv2 and was generated by KLEE
(set-option :produce-models true)
(set-logic QF_AUFBV )
; Array declarations
(declare-fun CommBufferSize () (Array (_ BitVec 32) (_ BitVec 8) ) )
; Constraints
; Constraints and QueryExpr
(assert
        (bvule 
               (_ bv16 64)
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
;   OK -- Elapsed: 8.852895e-03s
;   Solvable: true
;     CommBufferSize = [16,0,0,0,0,0,0,0]

; Query 2 -- Type: InitialValues, Instructions: 13472
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
                 (bvult 
                        (_ bv0 64)
                        (bvadd 
                               (_ bv18446744073709551600 64)
                               ?B1
                        )
                 )
                 (bvule 
                        (_ bv16 64)
                        ?B1
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
;   OK -- Elapsed: 7.357955e-03s
;   Solvable: true
;     CommBufferSize = [128,0,0,0,0,0,0,0]
