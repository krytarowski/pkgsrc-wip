# $NetBSD$

BUILDLINK_TREE+=	polly

.if !defined(POLLY_BUILDLINK3_MK)
POLLY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.polly+=	polly>=4.0.0nb20160911
BUILDLINK_PKGSRCDIR.polly?=	../../wip/polly-git

.include "../../wip/llvm-git/buildlink3.mk"
.endif	# POLLY_BUILDLINK3_MK

BUILDLINK_TREE+=	-polly
