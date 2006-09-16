# $NetBSD: Makefile,v 1.17 2006/09/16 06:55:10 thomasklausner Exp $
#

DISTNAME=		Firebird-2.0.0.12710-ReleaseCandidate3
PKGNAME=		firebird-2.0.0.12710rc3
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=firebird/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		nel@soraneko.com
HOMEPAGE=		http://www.firebirdsql.org/
COMMENT=		SQL database, opensource version of InterBase

WRKSRC=			${WRKDIR}/firebird-2.0.0.12710-ReleaseCandidate3
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
HAS_CONFIGURE=		yes
CONFIGURE_ENV+=		AUTOCONF=${LOCALBASE}/bin/autoconf
CONFIGURE_SCRIPT=	./autogen.sh
CONFIGURE_ARGS+=	--prefix=${PREFIX}/firebird
USE_TOOLS+=		autoconf gm4:run gmake

PKG_USERS=		firebird:firebird
PKG_GROUPS=		firebird

.include "../../mk/bsd.pkg.mk"
