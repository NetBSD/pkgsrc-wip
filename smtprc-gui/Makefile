# $NetBSD: Makefile,v 1.3 2004/05/09 21:44:19 blef Exp $

.include "../../wip/smtprc/Makefile.common"

PKGNAME=        ${DISTNAME:S/-/-gui-/}

COMMENT=	Open relay scanner Tk GUI

DEPENDS+=	smtprc-[0-9]*:../../wip/smtprc
DEPENDS+=	p5-Tk>=800.024:../../x11/p5-Tk

NO_CONFIGURE=	YES
NO_BUILD=	YES
USE_PERL5=	YES

PKGDIR=         ${.CURDIR}/../../wip/smtprc
PLIST_SRC=	${.CURDIR}/PLIST

REPLACE_PERL=	gsmtprc

pre-install:
	@${SED} -e 's#@PREFIX@#${PREFIX}#g' \
		-e 's#@PKG_SYSCONFDIR@#${PKG_SYSCONFDIR}#g' \
		< ${WRKSRC}/gsmtprc > ${WRKSRC}/gsmtprc.new

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gsmtprc.new ${PREFIX}/bin/gsmtprc
	${INSTALL_MAN} ${WRKSRC}/gsmtprc.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
