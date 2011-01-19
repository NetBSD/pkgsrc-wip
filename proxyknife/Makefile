# $NetBSD: Makefile,v 1.9 2011/01/19 20:49:02 gschwarz Exp $

DISTNAME=	proxyknife-1.7
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GNU:=proxyknife/}

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/proxyknife/proxyknife.html
COMMENT=	Proxyknife is a tool to validate free proxies
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
INFO_FILES=	YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=	perl gmake
USE_FEATURES+=	snprintf

CONFIGURE_ARGS+=	--docdir=${PREFIX}/share/doc/proxyknife
CPPFLAGS.SunOS+=	-DHAVE_LOCALE_H # apparently not automatically detected

CONF_FILES=	${DESTDIR}${PREFIX}/share/doc/proxyknife/example/proxyknife.conf.example ${DESTDIR}${PKG_SYSCONFDIR}/proxyknife.conf

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
