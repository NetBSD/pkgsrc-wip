# $NetBSD: Makefile,v 1.2 2003/12/30 23:57:35 cjep Exp $

.include "../../wip/smtprc/Makefile.common"

PKGNAME=        ${DISTNAME:S/-/-gui-/}

COMMENT=	Open relay scanner Tk GUI

USE_BUILDLINK2=	YES

DEPENDS+=	smtprc-[0-9]*:../../wip/smtprc

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

.include "../../x11/p5-Tk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
