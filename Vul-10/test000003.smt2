; This file conforms to SMTLIBv2 and was generated by KLEE
(set-logic QF_AUFBV )
; Array declarations
(declare-fun *CommBufferSize () (Array (_ BitVec 32) (_ BitVec 8) ) )
(declare-fun mVariableBufferPayloadSize () (Array (_ BitVec 32) (_ BitVec 8) ) )
; Constraints
; Constraints and QueryExpr
(assert
        (and 
             (= 
                (_ bv0 64)
                (concat 
                        (select 
                                mVariableBufferPayloadSize
                                (_ bv7 32)
                        )
                        (concat 
                                (select 
                                        mVariableBufferPayloadSize
                                        (_ bv6 32)
                                )
                                (concat 
                                        (select 
                                                mVariableBufferPayloadSize
                                                (_ bv5 32)
                                        )
                                        (concat 
                                                (select 
                                                        mVariableBufferPayloadSize
                                                        (_ bv4 32)
                                                )
                                                (concat 
                                                        (select 
                                                                mVariableBufferPayloadSize
                                                                (_ bv3 32)
                                                        )
                                                        (concat 
                                                                (select 
                                                                        mVariableBufferPayloadSize
                                                                        (_ bv2 32)
                                                                )
                                                                (concat 
                                                                        (select 
                                                                                mVariableBufferPayloadSize
                                                                                (_ bv1 32)
                                                                        )
                                                                        (select 
                                                                                mVariableBufferPayloadSize
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
             (bvult 
                    (concat 
                            (select 
                                    *CommBufferSize
                                    (_ bv7 32)
                            )
                            (concat 
                                    (select 
                                            *CommBufferSize
                                            (_ bv6 32)
                                    )
                                    (concat 
                                            (select 
                                                    *CommBufferSize
                                                    (_ bv5 32)
                                            )
                                            (concat 
                                                    (select 
                                                            *CommBufferSize
                                                            (_ bv4 32)
                                                    )
                                                    (concat 
                                                            (select 
                                                                    *CommBufferSize
                                                                    (_ bv3 32)
                                                            )
                                                            (concat 
                                                                    (select 
                                                                            *CommBufferSize
                                                                            (_ bv2 32)
                                                                    )
                                                                    (concat 
                                                                            (select 
                                                                                    *CommBufferSize
                                                                                    (_ bv1 32)
                                                                            )
                                                                            (select 
                                                                                    *CommBufferSize
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
(exit)
