; This file conforms to SMTLIBv2 and was generated by KLEE
(set-logic QF_AUFBV )
; Array declarations
(declare-fun CommBuffer->Function () (Array (_ BitVec 32) (_ BitVec 8) ) )
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
                 (and 
                      (= 
                         false
                         (bvult 
                                ?B1
                                (_ bv16 64)
                         )
                      )
                      (= 
                         false
                         (bvult 
                                (_ bv0 64)
                                (bvadd 
                                       (_ bv18446744073709551600 64)
                                       ?B1
                                )
                         )
                      )
                 )
                 (= 
                    (_ bv10 64)
                    (concat 
                            (select 
                                    CommBuffer->Function
                                    (_ bv7 32)
                            )
                            (concat 
                                    (select 
                                            CommBuffer->Function
                                            (_ bv6 32)
                                    )
                                    (concat 
                                            (select 
                                                    CommBuffer->Function
                                                    (_ bv5 32)
                                            )
                                            (concat 
                                                    (select 
                                                            CommBuffer->Function
                                                            (_ bv4 32)
                                                    )
                                                    (concat 
                                                            (select 
                                                                    CommBuffer->Function
                                                                    (_ bv3 32)
                                                            )
                                                            (concat 
                                                                    (select 
                                                                            CommBuffer->Function
                                                                            (_ bv2 32)
                                                                    )
                                                                    (concat 
                                                                            (select 
                                                                                    CommBuffer->Function
                                                                                    (_ bv1 32)
                                                                            )
                                                                            (select 
                                                                                    CommBuffer->Function
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
        )
)
(check-sat)
(exit)
