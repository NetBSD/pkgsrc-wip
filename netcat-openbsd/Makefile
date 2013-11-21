# $NetBSD: Makefile,v 1.1 2013/11/21 02:27:02 genolopolis Exp $
#

PKGNAME=	netcat-openbsd-1
CATEGORIES=	net
MASTER_SITES=	# empty
DISTFILES=	# empty
LICENSE=		modified-bsd

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.openbsd.org/
COMMENT=	Arbitrary TCP and UDP connections and listens
CONFLICTS=	netcat-[0-9]*

NO_CONFIGURE=	yes

do-extract:
	${CP} -r ${FILESDIR} ${WRKSRC}

do-build:
	cd ${WRKSRC} \
		&& env ${MAKE_ENV} \
		&& ${CC} -o nc netcat.c atomicio.c socks.c strtonum.c readpassphrase.c

do-install:
	cd ${WRKSRC} \
		&& install -d ${DESTDIR}/${PREFIX}/bin/ \
		&& install nc ${DESTDIR}/${PREFIX}/bin/nc \
		&& install -d ${DESTDIR}/${PREFIX}/${PKGMANDIR}/${PKGMANDIR}1/ \
		&& install -m 0644 nc.1 ${DESTDIR}/${PREFIX}/${PKGMANDIR}/${PKGMANDIR}1/nc.1

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
