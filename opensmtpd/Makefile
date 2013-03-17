# $NetBSD: Makefile,v 1.6 2013/03/17 20:36:38 ftigeot Exp $

VERSION=	5.3p1
DISTNAME=	opensmtpd-${VERSION}
CATEGORIES=	mail net
MASTER_SITES=	http://www.opensmtpd.org/archives/

MAINTAINER=	ftigeot@wolfpond.org
HOMEPAGE=	http://www.opensmtpd.org/
COMMENT=	The OpenSMTPD mail transfer agent, a replacement for sendmail
LICENSE=	isc

#WRKSRC=		${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	c
USE_LIBTOOL=	yes
USE_TOOLS+=	automake aclocal autoheader autoconf

GNU_CONFIGURE=	yes

EXAMPLEDIR=	${PREFIX}/share/examples/opensmtpd
CONF_FILES=	${EXAMPLEDIR}/smtpd.conf ${PKG_SYSCONFDIR}/smtpd.conf

SUBST_CLASSES+=			exampledir
SUBST_STAGE.exampledir=		pre-configure
SUBST_MESSAGE.exampledir=	Fixing exampledir path
SUBST_FILES.exampledir=		smtpd/Makefile.am
SUBST_SED.exampledir+=		-e 's,@EXAMPLE_DIR@,${EXAMPLEDIR},'

pre-configure:
	set -e; cd ${WRKSRC}; \
	./bootstrap

.include "../../devel/libevent/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
