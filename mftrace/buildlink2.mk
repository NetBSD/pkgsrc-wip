BUILDLINK_PACKAGES+=          mftrace
BUILDLINK_PKGBASE.mftrace=        mftrace
BUILDLINK_DEPENDS.mftrace?=       mftrace>=1.0.19
BUILDLINK_PKGSRCDIR.mftrace?=     ../../wip/mftrace

EVAL_PREFIX+=                 BUILDLINK_PREFIX.mftrace=mftrace
BUILDLINK_PREFIX.mftrace_DEFAULT= ${LOCALBASE}

BUILDLINK_TARGETS+=           mftrace-buildlink

mftrace-buildlink: _BUILDLINK_USE
