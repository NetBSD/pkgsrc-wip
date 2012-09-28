# $NetBSD: Makefile,v 1.4 2012/09/28 23:21:47 asau Exp $
#

DISTNAME=	fail2ban-0.8.4
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fail2ban/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rhaamo@gruik.at
HOMEPAGE=	http://www.fail2ban.org/
COMMENT=	Scans log files and bans IP that makes too many password failures
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none

INSTALLATION_DIRS+=	${PKGMANDIR}/man1/

MANPAGES=		fail2ban-client.1 fail2ban-regex.1 fail2ban-server.1

FILES_SUBST+=		PYTHON_INTERP=${PYTHONBIN:Q}
BUILD_DEFS+=		PYTHON_INTERP

RCD_SCRIPTS=	fail2ban

post-install:
.for f in ${MANPAGES}
	${INSTALL_MAN} ${WRKSRC}/man/${f} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
.endfor

.include "options.mk"

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
