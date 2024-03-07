; This file conforms to SMTLIBv2 and was generated by KLEE
(set-logic QF_AUFBV )
; Array declarations
(declare-fun *CommBufferSize () (Array (_ BitVec 32) (_ BitVec 8) ) )
(declare-fun CommBuffer->Header.Command () (Array (_ BitVec 32) (_ BitVec 8) ) )
(declare-fun CommBuffer->ProfileBuffer () (Array (_ BitVec 32) (_ BitVec 8) ) )
(declare-fun CommBuffer->ProfileOffset () (Array (_ BitVec 32) (_ BitVec 8) ) )
(declare-fun CommBuffer->ProfileSize () (Array (_ BitVec 32) (_ BitVec 8) ) )
(declare-fun mSmramReadyToLock () (Array (_ BitVec 32) (_ BitVec 8) ) )
; Constraints
; Constraints and QueryExpr
(assert
        (and 
             (and 
                  (and 
                       (and 
                            (and 
                                 (= 
                                    false
                                    (= 
                                       (_ bv0 64)
                                       (concat 
                                               (select 
                                                       CommBuffer->ProfileOffset
                                                       (_ bv7 32)
                                               )
                                               (concat 
                                                       (select 
                                                               CommBuffer->ProfileOffset
                                                               (_ bv6 32)
                                                       )
                                                       (concat 
                                                               (select 
                                                                       CommBuffer->ProfileOffset
                                                                       (_ bv5 32)
                                                               )
                                                               (concat 
                                                                       (select 
                                                                               CommBuffer->ProfileOffset
                                                                               (_ bv4 32)
                                                                       )
                                                                       (concat 
                                                                               (select 
                                                                                       CommBuffer->ProfileOffset
                                                                                       (_ bv3 32)
                                                                               )
                                                                               (concat 
                                                                                       (select 
                                                                                               CommBuffer->ProfileOffset
                                                                                               (_ bv2 32)
                                                                                       )
                                                                                       (concat 
                                                                                               (select 
                                                                                                       CommBuffer->ProfileOffset
                                                                                                       (_ bv1 32)
                                                                                               )
                                                                                               (select 
                                                                                                       CommBuffer->ProfileOffset
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
                                 (= 
                                    false
                                    (= 
                                       (_ bv0 64)
                                       (concat 
                                               (select 
                                                       CommBuffer->ProfileBuffer
                                                       (_ bv7 32)
                                               )
                                               (concat 
                                                       (select 
                                                               CommBuffer->ProfileBuffer
                                                               (_ bv6 32)
                                                       )
                                                       (concat 
                                                               (select 
                                                                       CommBuffer->ProfileBuffer
                                                                       (_ bv5 32)
                                                               )
                                                               (concat 
                                                                       (select 
                                                                               CommBuffer->ProfileBuffer
                                                                               (_ bv4 32)
                                                                       )
                                                                       (concat 
                                                                               (select 
                                                                                       CommBuffer->ProfileBuffer
                                                                                       (_ bv3 32)
                                                                               )
                                                                               (concat 
                                                                                       (select 
                                                                                               CommBuffer->ProfileBuffer
                                                                                               (_ bv2 32)
                                                                                       )
                                                                                       (concat 
                                                                                               (select 
                                                                                                       CommBuffer->ProfileBuffer
                                                                                                       (_ bv1 32)
                                                                                               )
                                                                                               (select 
                                                                                                       CommBuffer->ProfileBuffer
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
                            (= 
                               false
                               (= 
                                  (_ bv0 64)
                                  (concat 
                                          (select 
                                                  CommBuffer->ProfileSize
                                                  (_ bv7 32)
                                          )
                                          (concat 
                                                  (select 
                                                          CommBuffer->ProfileSize
                                                          (_ bv6 32)
                                                  )
                                                  (concat 
                                                          (select 
                                                                  CommBuffer->ProfileSize
                                                                  (_ bv5 32)
                                                          )
                                                          (concat 
                                                                  (select 
                                                                          CommBuffer->ProfileSize
                                                                          (_ bv4 32)
                                                                  )
                                                                  (concat 
                                                                          (select 
                                                                                  CommBuffer->ProfileSize
                                                                                  (_ bv3 32)
                                                                          )
                                                                          (concat 
                                                                                  (select 
                                                                                          CommBuffer->ProfileSize
                                                                                          (_ bv2 32)
                                                                                  )
                                                                                  (concat 
                                                                                          (select 
                                                                                                  CommBuffer->ProfileSize
                                                                                                  (_ bv1 32)
                                                                                          )
                                                                                          (select 
                                                                                                  CommBuffer->ProfileSize
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
                       (= 
                          (_ bv0 8)
                          (select 
                                  mSmramReadyToLock
                                  (_ bv0 32)
                          )
                       )
                  )
                  (= 
                     (_ bv7 32)
                     (concat 
                             (select 
                                     CommBuffer->Header.Command
                                     (_ bv3 32)
                             )
                             (concat 
                                     (select 
                                             CommBuffer->Header.Command
                                             (_ bv2 32)
                                     )
                                     (concat 
                                             (select 
                                                     CommBuffer->Header.Command
                                                     (_ bv1 32)
                                             )
                                             (select 
                                                     CommBuffer->Header.Command
                                                     (_ bv0 32)
                                             )
                                     )
                             )
                     )
                  )
             )
             (= 
                (_ bv24 64)
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
             )
        )
)
(check-sat)
(exit)
