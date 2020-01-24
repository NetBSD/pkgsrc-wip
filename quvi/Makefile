# $NetBSD: Makefile,v 1.22 2014/05/03 13:14:38 alnsn Exp $
#

DISTNAME=	quvi-0.9.5
PKGREVISION=	6
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=quvi/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://quvi.sourceforge.net/
COMMENT=	Command line tool for parsing video links
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

BUILDLINK_API_DEPENDS.curl+=		curl>=7.18.2
.include "../../www/curl/buildlink3.mk"
BUILDLINK_API_DEPENDS.libquvi+=		libquvi>=0.9
.include "../../wip/libquvi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
