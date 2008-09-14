# $NetBSD: Makefile,v 1.3 2008/09/14 18:23:43 jakllsch Exp $

DISTNAME=	kstart-3.14
CATEGORIES=	sysutils
MASTER_SITES=	http://archives.eyrie.org/software/kerberos/

MAINTAINER=	jakllsch@NetBSD.org
HOMEPAGE=	http://www.eyrie.org/~eagle/software/kstart/
COMMENT=	Run a process with Kerberos credentials

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--disable-k4start

# As the NetBSD base system doesn't ship with afslog
# (or pagsh), and pkgsrc heimdal and pkgsrc openafs
# conflict; I've made the path to (ak|afs)log selectable.

BUILD_DEFS+= KSTART_PATH_AKLOG
KSTART_PATH_AKLOG?= /usr/local/bin/afslog
.include "../../mk/bsd.prefs.mk"
CONFIGURE_ARGS+=	--with-aklog=${KSTART_PATH_AKLOG:Q}

.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
