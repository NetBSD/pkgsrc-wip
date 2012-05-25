# $NetBSD: Makefile,v 1.4 2012/05/25 09:43:31 ftigeot Exp $

DISTNAME=	opensmtpd-201205241358
CATEGORIES=	mail net
MASTER_SITES=	http://www.opensmtpd.org/archives/

MAINTAINER=	ftigeot@wolfpond.org
HOMEPAGE=	http://www.opensmtpd.org/
COMMENT=	The OpenSMTPD mail transfer agent, a replacement for sendmail
LICENSE=	isc

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/opensmtpd

USE_LANGUAGES=	c
USE_LIBTOOL=	yes
USE_TOOLS+=	automake aclocal autoheader autoconf

GNU_CONFIGURE=	yes

EXAMPLEDIR=	${PREFIX}/share/examples/opensmtpd
CONF_FILES=	${EXAMPLEDIR}/smtpd.conf ${PKG_SYSCONFDIR}/smtpd.conf

SUBST_CLASSES+=			exampledir
SUBST_STAGE.exampledir=		pre-configure
SUBST_MESSAGE.exampledir=	Fixing exampledir path
SUBST_FILES.exampledir=		src/Makefile.am
SUBST_SED.exampledir+=		-e 's,@EXAMPLE_DIR@,${EXAMPLEDIR},'

pre-configure:
	set -e; cd ${WRKSRC}; \
	./bootstrap

.include "../../devel/libevent/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
