# $NetBSD: buildlink2.mk,v 1.1.1.1 2004/11/19 21:49:17 daprice Exp $
#
# This Makefile fragment is included by packages that use libGenome.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(LIBGENOME_BUILDLINK2_MK)
LIBGENOME_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libGenome
BUILDLINK_DEPENDS.libGenome?=		libGenome>=0.5.2
BUILDLINK_PKGSRCDIR.libGenome?=		../../biology/libGenome

EVAL_PREFIX+=	BUILDLINK_PREFIX.libGenome=libGenome
BUILDLINK_PREFIX.libGenome_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libGenome+=	include/gn/gnABISource.h
BUILDLINK_FILES.libGenome+=	include/gn/gnBaseFeature.h
BUILDLINK_FILES.libGenome+=	include/gn/gnBaseFilter.h
BUILDLINK_FILES.libGenome+=	include/gn/gnBaseHeader.h
BUILDLINK_FILES.libGenome+=	include/gn/gnBaseQualifier.h
BUILDLINK_FILES.libGenome+=	include/gn/gnBaseSource.h
BUILDLINK_FILES.libGenome+=	include/gn/gnBaseSpec.h
BUILDLINK_FILES.libGenome+=	include/gn/gnClone.h
BUILDLINK_FILES.libGenome+=	include/gn/gnCompare.h
BUILDLINK_FILES.libGenome+=	include/gn/gnContigSpec.h
BUILDLINK_FILES.libGenome+=	include/gn/gnDNASequence.h
BUILDLINK_FILES.libGenome+=	include/gn/gnDNXSource.h
BUILDLINK_FILES.libGenome+=	include/gn/gnDataBaseSource.h
BUILDLINK_FILES.libGenome+=	include/gn/gnDebug.h
BUILDLINK_FILES.libGenome+=	include/gn/gnDefs.h
BUILDLINK_FILES.libGenome+=	include/gn/gnException.h
BUILDLINK_FILES.libGenome+=	include/gn/gnExceptionCode.h
BUILDLINK_FILES.libGenome+=	include/gn/gnFASSource.h
BUILDLINK_FILES.libGenome+=	include/gn/gnFastTranslator.h
BUILDLINK_FILES.libGenome+=	include/gn/gnFeature.h
BUILDLINK_FILES.libGenome+=	include/gn/gnFileContig.h
BUILDLINK_FILES.libGenome+=	include/gn/gnFileSource.h
BUILDLINK_FILES.libGenome+=	include/gn/gnFilter.h
BUILDLINK_FILES.libGenome+=	include/gn/gnFragmentSpec.h
BUILDLINK_FILES.libGenome+=	include/gn/gnGBKSource.h
BUILDLINK_FILES.libGenome+=	include/gn/gnGenomeSpec.h
BUILDLINK_FILES.libGenome+=	include/gn/gnLocation.h
BUILDLINK_FILES.libGenome+=	include/gn/gnMultiSpec.h
BUILDLINK_FILES.libGenome+=	include/gn/gnPosSpecificTranslator.h
BUILDLINK_FILES.libGenome+=	include/gn/gnProteinSequence.h
BUILDLINK_FILES.libGenome+=	include/gn/gnRAWSource.h
BUILDLINK_FILES.libGenome+=	include/gn/gnRNASequence.h
BUILDLINK_FILES.libGenome+=	include/gn/gnSEQSource.h
BUILDLINK_FILES.libGenome+=	include/gn/gnSequence.h
BUILDLINK_FILES.libGenome+=	include/gn/gnSetup.h
BUILDLINK_FILES.libGenome+=	include/gn/gnSourceFactory.h
BUILDLINK_FILES.libGenome+=	include/gn/gnSourceHeader.h
BUILDLINK_FILES.libGenome+=	include/gn/gnSourceQualifier.h
BUILDLINK_FILES.libGenome+=	include/gn/gnSourceSpec.h
BUILDLINK_FILES.libGenome+=	include/gn/gnStringHeader.h
BUILDLINK_FILES.libGenome+=	include/gn/gnStringQualifier.h
BUILDLINK_FILES.libGenome+=	include/gn/gnStringSpec.h
BUILDLINK_FILES.libGenome+=	include/gn/gnStringTools.h
BUILDLINK_FILES.libGenome+=	include/gn/gnTranslator.h
BUILDLINK_FILES.libGenome+=	include/gn/gnVersion.h
BUILDLINK_FILES.libGenome+=	lib/libGenome.*

BUILDLINK_TARGETS+=	libGenome-buildlink

libGenome-buildlink: _BUILDLINK_USE

.endif	# LIBGENOME_BUILDLINK2_MK
