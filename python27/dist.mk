# $NetBSD: dist.mk,v 1.3 2010/11/28 13:04:23 obache Exp $

PY_DISTVERSION=	2.7.1
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.bz2
DISTINFO_FILE=	${.CURDIR}/../../wip/python27/distinfo
PATCHDIR=	${.CURDIR}/../../wip/python27/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
