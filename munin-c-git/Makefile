# $NetBSD: $

VERSION=	0.0.9
DISTNAME=	munin-c-${VERSION}
COMMENT=	System monitoring tool, client version and plugin in C
CATEGORIES=	sysutils
WRKSRC=         ${WRKDIR}/munin-c

MAINTAINER=	tm@core.io
HOMEPAGE=	http://munin-monitoring.org/
LICENSE=	gnu-gpl-v2

GIT_REPOSITORIES=	master
GIT_REPO.master=	git://github.com/munin-monitoring/munin-c.git
GIT_MODULE.master=	munin-c

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config autoconf aclocal autoheader automake perl

LIBS.SunOS+=    -lnsl -lsocket

pre-configure:
	cd ${WRKSRC} && \
		libtoolize --force && \
		autoreconf --install && \
		autoreconf -i -I m4


.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
