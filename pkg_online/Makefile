# $NetBSD: Makefile,v 1.10 2008/05/11 15:32:58 cheusov Exp $
#

DISTNAME=	pkg_online-0.4.0
CATEGORIES=	pkgtools
MASTER_SITES=	http://mova.org/~cheusov/pub/pkg_online/

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://mova.org/~cheusov/pub/pkg_online/
COMMENT=	Client/Server search in pkgsrc packages

DEPENDS+=	dict-server>=1.10.10nb2:../../wip/dict-server
DEPENDS+=	dict-client>=1.10.9:../../wip/dict-client
DEPENDS+=	pkg_summary-utils-[0-9]*:../../wip/pkg_summary-utils
DEPENDS+=	pipestatus-[0-9]*:../../wip/pipestatus
DEPENDS+=	netcat-[0-9]*:../../net/netcat

INSTALLATION_DIRS+=	share/doc/pkg_online

USE_LANGUAGES=		# none
USE_BSD_MAKEFILE=	yes

NO_BUILD=		yes

.include "../../mk/bsd.pkg.mk"
