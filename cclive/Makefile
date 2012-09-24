# $NetBSD: Makefile,v 1.20 2012/09/24 18:26:52 asau Exp $
#

DISTNAME=		cclive-0.7.8
PKGREVISION=		1
CATEGORIES=		net multimedia www
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=cclive/}

MAINTAINER=		zecrazytux@zecrazytux.net
HOMEPAGE=		http://cclive.sourceforge.net/
COMMENT=		Command line video extraction tool for user-uploaded video hosts
LICENSE=		gnu-gpl-v3

USE_LANGUAGES=		c++ c
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

.include "../../mk/compiler.mk"
# GCC 4.4 and above needs this
.if !empty(PKGSRC_COMPILER:Mgcc) && !empty(CC_VERSION:Mgcc-4.[4-9]*)
CXXFLAGS+=		-std=c++0x
.endif

BUILDLINK_API_DEPENDS.quvi+=	quvi>=0.2.16.1
.include "../../net/libquvi/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/pcre++/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
