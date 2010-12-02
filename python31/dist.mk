# $NetBSD: dist.mk,v 1.2 2010/12/02 12:16:13 obache Exp $

PY_DISTVERSION=	3.1.3
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.bz2
DISTINFO_FILE=	${.CURDIR}/../../wip/python31/distinfo
PATCHDIR=	${.CURDIR}/../../wip/python31/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
