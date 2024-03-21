; This file conforms to SMTLIBv2 and was generated by KLEE
(set-logic QF_AUFBV )
; Array declarations
(declare-fun *CommBufferSize () (Array (_ BitVec 32) (_ BitVec 8) ) )
(declare-fun mSmramReadyToLock () (Array (_ BitVec 32) (_ BitVec 8) ) )
; Constraints
; Constraints and QueryExpr
(assert
        (and 
             (= 
                false
                (bvult 
                       ((_ zero_extend 32) 
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
                       (_ bv16 64)
                )
             )
             (= 
                false
                (= 
                   (_ bv0 8)
                   (select 
                           mSmramReadyToLock
                           (_ bv0 32)
                   )
                )
             )
        )
)
(check-sat)
(exit)