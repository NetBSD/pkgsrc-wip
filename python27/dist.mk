# $NetBSD: dist.mk,v 1.1 2010/09/17 09:09:11 obache Exp $

PY_DISTVERSION=	2.7
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.bz2
DISTINFO_FILE=	${.CURDIR}/../../wip/python27/distinfo
PATCHDIR=	${.CURDIR}/../../wip/python27/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
