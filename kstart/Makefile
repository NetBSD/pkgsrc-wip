# $NetBSD: Makefile,v 1.5 2010/02/05 21:52:31 jakllsch Exp $

DISTNAME=	kstart-3.16
CATEGORIES=	sysutils
MASTER_SITES=	http://archives.eyrie.org/software/kerberos/

MAINTAINER=	jakllsch@NetBSD.org
HOMEPAGE=	http://www.eyrie.org/~eagle/software/kstart/
COMMENT=	Run a process with Kerberos credentials
LICENSE=	mit

PKG_DESTDIR_SUPPORT= user-destdir

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--disable-k4start
CONFIGURE_ARGS+=	--enable-setpag

# As the NetBSD base system doesn't ship with afslog
# and pkgsrc heimdal and pkgsrc openafs conflict;
# the path to (ak|afs)log is configurable.

BUILD_DEFS+= KSTART_PATH_AKLOG
KSTART_PATH_AKLOG?= ${PREFIX}/bin/afslog
.include "../../mk/bsd.prefs.mk"
CONFIGURE_ARGS+=	--with-aklog=${KSTART_PATH_AKLOG:Q}

.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
