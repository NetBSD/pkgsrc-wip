# $NetBSD: Makefile,v 1.11 2005/05/24 10:29:41 rillig Exp $
#

DISTNAME=		firebird-1.5.0.4290
PKGNAME=		${DISTNAME:S/.4290//}
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=firebird/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://firebird.sf.net/
COMMENT=		SQL database, opensource version of InterBase

WRKSRC=			${WRKDIR}/firebird15
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
PREFIX=			${LOCALBASE}/firebird15

CONFIGURE_ARGS+=	--with-lock-manager
CONFIGURE_ARGS+=	--with-editline
CONFIGURE_ENV+=		AUTOCONF=${AUTOCONF}
CONFIGURE_ENV+=		AUTOMAKE=${AUTOMAKE}

# Yes, such versions are required, you won't build this package without
# those:
AUTOCONF_REQD=		2.53
GCC_REQD=		3.3.0
USE_GNU_TOOLS+=		m4 		# needs GNU M4 version 4.14

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		./autogen.sh ${CONFIGURE_ARGS}

.include "../../mk/autoconf.mk"
.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"
