# $NetBSD: Makefile,v 1.1.1.1 2004/09/16 15:39:59 airhead Exp $
#

DISTNAME=		ecore-1.0.0_pre7
PKGNAME=		ecore-1.0.0
PKGREVISION=		1
CATEGORIES=		wip x11 devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=enlightenment/}

MAINTAINER=		Peter.Bex@student.kun.nl
HOMEPAGE=		http://www.enlightenment.org/pages/ecore.html
COMMENT=		Core events/X abstraction layer for Enlightenment

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
USE_X11=		YES

.include "../../devel/libtool/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../wip/evas/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
