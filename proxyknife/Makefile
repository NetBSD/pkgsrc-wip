# $NetBSD: Makefile,v 1.2 2006/12/06 16:09:26 gschwarz Exp $

DISTNAME=	proxyknife-1.6
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GNU:=proxyknife/}

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/proxyknife/proxyknife.html
COMMENT=	Proxyknife is a tool to validate free proxies

GNU_CONFIGURE=	YES
INFO_FILES=	YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=	perl

# starting the install binary with /bin/sh does not work
# since it is no shell script
SUBST_CLASSES+=		install
SUBST_STAGE.install=	post-configure
SUBST_FILES.install=	Makefile doc/Makefile gl/Makefile intl/Makefile po/Makefile scripts/Makefile scripts/Makefile
SUBST_SED.install=	-e 's,^mkinstalldirs\ =\ \$$(SHELL)\ ,mkinstalldirs\ =\ ,'

.include "../../mk/bsd.prefs.mk"
.if !empty(LOWER_OPSYS:Mirix5*)
# needs snprintf
. include "../../pkgtools/libnbcompat/buildlink3.mk"
.endif
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
