# $NetBSD: Makefile,v 1.3 2004/05/08 18:45:12 blef Exp $
# FreeBSD Id: ports/www/mod_frontpage/Makefile,v 1.12 2002/05/23 22:38:29 mbr Exp

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

USE_BUILDLINK3=	YES
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
CONFIGURE_ENV+=	PREFIX=${PREFIX}

MAKE_ENV+=	APACHE_USER="${APACHE_USER}" APACHE_GROUP="${APACHE_GROUP}"
MAKE_ENV+=	APACHE_SUEXEC_DOCROOT="${APACHE_SUEXEC_DOCROOT}"
MAKE_ENV+=	FP_UID_MIN="${FP_UID_MIN}" FP_GID_MIN="${FP_GID_MIN}"
MAKE_ENV+=	APXS="${AXPS}" FPOWN="${FPOWN}" FPGRP="${FPGRP}"

BUILD_DEFS+=	APACHE_USER APACHE_GROUP APACHE_SUEXEC_DOCROOT
BUILD_DEFS+=	FP_UID_MIN FP_GID_MIN FPOWN FPGRP

.include "../../lang/perl5/module.mk"
.include "../../www/apache/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
