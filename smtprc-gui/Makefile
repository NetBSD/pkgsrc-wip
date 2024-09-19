# $NetBSD: Makefile,v 1.7 2012/10/07 15:39:31 asau Exp $

.include "../../wip/smtprc/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-gui-/}

COMMENT=	Open relay scanner Tk GUI

DEPENDS+=	smtprc-[0-9]*:../../wip/smtprc
DEPENDS+=	p5-Tk>=800.024:../../x11/p5-Tk

NO_CONFIGURE=	YES
NO_BUILD=	YES
USE_TOOLS+=	perl

PKGDIR=		${.CURDIR}/../../wip/smtprc
PLIST_SRC=	${.CURDIR}/PLIST

REPLACE_PERL=	gsmtprc

pre-install:
	@${SED} -e 's#@PREFIX@#${PREFIX}#g' \
		-e 's#@PKG_SYSCONFDIR@#${PKG_SYSCONFDIR}#g' \
		< ${WRKSRC}/gsmtprc > ${WRKSRC}/gsmtprc.new

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gsmtprc.new ${DESTDIR}${PREFIX}/bin/gsmtprc
	${INSTALL_MAN} ${WRKSRC}/gsmtprc.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
