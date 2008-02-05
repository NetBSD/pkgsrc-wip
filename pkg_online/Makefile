# $NetBSD: Makefile,v 1.4 2008/02/05 22:35:33 cheusov Exp $
#

DISTNAME=	pkg_online-0.3.0
CATEGORIES=	pkgtools
MASTER_SITES=	http://mova.org/~cheusov/pub/pkg_online/

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://mova.org/~cheusov/pub/pkg_online/
COMMENT=	Client/Server search in pkgsrc packages

DEPENDS+=	dict-server>=1.10.10nb2:../../wip/dict-server
DEPENDS+=	dict-client>=1.10.9:../../wip/dict-client
DEPENDS+=	pkg_src_summary-[0-9]*:../../wip/pkg_src_summary
DEPENDS+=	pkg_summary4view-[0-9]*:../../wip/pkg_summary4view
DEPENDS+=	pipestatus-[0-9]*:../../wip/pipestatus
DEPENDS+=	netcat-[0-9]*:../../net/netcat

INSTALLATION_DIRS+=	share/doc/pkg_online

USE_LANGUAGES=		# none
NO_BUILD=		yes

.include "../../mk/bsd.pkg.mk"
