# $NetBSD: Makefile,v 1.7 2005/11/28 00:27:23 rillig Exp $

DISTNAME=	mod_frontpage_mirfak-${M_FPVERSION}
PKGNAME=	ap-frontpage-${M_FPVERSION}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mirfak/}
# DISTFILES=	${DISTNAME:C/-[^-]*$//}_mirfak-${M_FPVERSION}.tar.gz

MAINTAINER=	eric@cirr.com
HOMEPAGE=	http://sourceforge.net/projects/mirfak
COMMENT=	Improved mod_frontpage for Apache

# WRKSRC=	${WRKDIR}/${DISTNAME:C/-[^-]*$//}_mirfak-${M_FPVERSION}

M_FPVERSION=	1.6.2

# APACHE_MODULE_NAME=	mod_frontpage.so

# RUN_DEPENDS=	${FPSETPERM}:../../www/frontpage

.include "../../mk/bsd.prefs.mk"

PKG_PREFIX=	${PREFIX}

# minimum UID and GID's for fpexec..
# you probably want to use the same values as for suexec
FP_UID_MIN?=	100
FP_GID_MIN?=	100

FPOWN?=		${BINOWN}
FPGRP?=		${BINGRP}

PERL5_CONFIGURE= yes
CONFIGURE_ENV+=	PREFIX=${PREFIX:Q}

MAKE_ENV+=	APACHE_USER=${APACHE_USER:Q} APACHE_GROUP=${APACHE_GROUP:Q}
MAKE_ENV+=	APACHE_SUEXEC_DOCROOT=${APACHE_SUEXEC_DOCROOT:Q}
MAKE_ENV+=	FP_UID_MIN=${FP_UID_MIN:Q} FP_GID_MIN=${FP_GID_MIN:Q}
MAKE_ENV+=	APXS=${AXPS:Q} FPOWN=${FPOWN:Q} FPGRP=${FPGRP:Q}

BUILD_DEFS+=	APACHE_USER APACHE_GROUP APACHE_SUEXEC_DOCROOT
BUILD_DEFS+=	FP_UID_MIN FP_GID_MIN FPOWN FPGRP

.include "../../lang/perl5/module.mk"
.include "../../www/apache/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
