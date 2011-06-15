# $NetBSD: dist.mk,v 1.3 2011/06/15 08:58:27 obache Exp $

PY_DISTVERSION=	3.1.4
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.bz2
DISTINFO_FILE=	${.CURDIR}/../../wip/python31/distinfo
PATCHDIR=	${.CURDIR}/../../wip/python31/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
