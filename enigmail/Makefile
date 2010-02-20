# $NetBSD: Makefile,v 1.2 2010/02/20 19:06:52 khorben Exp $
#

DISTNAME=	enigmail-0.96.0
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.mozilla-enigmail.org/download/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://enigmail.mozdev.org/home/index.php
COMMENT=	GnuPG support for mail/thunderbird

WRKSRC=		${WRKDIR}/enigmail
USE_LANGUAGES=	c c++
USE_TOOLS=	gmake pax perl

PKG_DESTDIR_SUPPORT=	user-destdir

REPLACE_PERL=	makemake ipc/makemake lang/make-lang-xpi.pl
REPLACE_PERL+=	${ENIGMAIL_WRKSRC}/makemake
REPLACE_PERL+=	${ENIGMAIL_WRKSRC}/ipc/makemake
REPLACE_PERL+=	${ENIGMAIL_WRKSRC}/lang/make-lang-xpi.pl

BUILD_DEPENDS+= 	thunderbird>=2.0.0.0:../../mail/thunderbird2
DEPENDS+=		gnupg-[0-9]*:../../security/gnupg

ENIGMAIL_WRKSRC=	${THUNDERBIRD_WRKSRC}/mailnews/extensions/enigmail
MAKE_THUNDERBIRD=	cd ${PKGDIR}/../../mail/thunderbird2 && \
			env -i ${MAKE} -f ${PKGDIR}/Makefile.thunderbird \
				WRKDIR=${THUNDERBIRD_WRKDIR} \
				WRKSRC=${THUNDERBIRD_WRKSRC}
THUNDERBIRD_WRKDIR=	${WRKDIR}/thunderbird2
THUNDERBIRD_WRKSRC=	${THUNDERBIRD_WRKDIR}/mozilla

ENIGMAILXPI=	${DISTNAME}-${LOWER_OPSYS}-${MACHINE_GNU_ARCH}.xpi
XPIFILE=	${THUNDERBIRD_WRKSRC}/dist/bin/${ENIGMAILXPI}
XPIDIR=		${PREFIX}/share

MESSAGE_SUBST+= ENIGMAILXPI=${ENIGMAILXPI} XPIDIR=${XPIDIR}

#post-fetch:
#	${MAKE_THUNDERBIRD} fetch

post-extract:
	${MAKE_THUNDERBIRD} extract
	${MKDIR} -p ${ENIGMAIL_WRKSRC}

post-patch:
	cd ${WRKSRC} && pax -r -w . ${ENIGMAIL_WRKSRC}

pre-configure:
	${MAKE_THUNDERBIRD} configure

pre-build:
	${MAKE_THUNDERBIRD} build-enigmail-prerequisites
	${MAKE_THUNDERBIRD} configure-enigmail

do-build:
	${MAKE_THUNDERBIRD} build-enigmail

do-install:
	${INSTALL_DATA_DIR} ${XPIDIR}
	${INSTALL_DATA} ${XPIFILE} ${XPIDIR}

.include "../../mk/bsd.pkg.mk"
