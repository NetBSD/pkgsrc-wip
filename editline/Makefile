# $NetBSD: Makefile,v 1.1.1.1 2005/01/12 19:29:00 jeremy-c-reed Exp $
#

DISTNAME=		libedit-20041207-2.9
PKGNAME=		editline-20041207.2.9
CATEGORIES=		devel
MASTER_SITES=		http://www.thrysoee.dk/editline/

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.thrysoee.dk/editline/
COMMENT=		NetBSD Editline library (libedit) for generic line editing

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes

#INSTALLATION_DIRS+=	include/editline

.include "../../mk/bsd.pkg.mk"
