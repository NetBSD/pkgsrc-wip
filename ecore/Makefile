# $NetBSD: Makefile,v 1.6 2006/05/01 01:32:00 shattered Exp $
#

DISTNAME=		ecore-1.0.0_pre7
PKGNAME=		ecore-1.0.0
PKGREVISION=		1
CATEGORIES=		x11 devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=enlightenment/}

MAINTAINER=		Peter.Bex@student.kun.nl
HOMEPAGE=		http://www.enlightenment.org/Libraries/Ecore/
COMMENT=		Core events/X abstraction layer for Enlightenment

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

.include "../../devel/libltdl/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../wip/evas/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
