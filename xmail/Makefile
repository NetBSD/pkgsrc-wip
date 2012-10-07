# $NetBSD: Makefile,v 1.11 2012/10/07 19:41:52 asau Exp $
#

DISTNAME=	xmail-1.18
CATEGORIES=	mail
MASTER_SITES=	http://www.xmailserver.com/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.xmailserver.com/
COMMENT=	SMTP, POP3 and finder server

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

MAKE_ENV+=	OSTYPE=${OPSYS:Q}

.include "../../mk/bsd.prefs.mk"

EXT=bsd # Default one :)
.if ${OPSYS} == "Linux"
.	if   ${MACHINE_ARCH} == "i86pc"
		EXT="lnx"
.	elif ${MACHINE_ARCH} == "sparc"
		EXT="slx"
.	elif ${MACHINE_ARCH} == "ppc"
		EXT="plx"
.	endif
.elif ${OPSYS} == "SunOS"
.	if   ${MACHINE_ARCH} == "sparc"
		EXT="sso"
.	elif ${MACHINE_ARCH} == "i86pc"
		EXT="ssx"
.	endif
.endif

MAKE_FILE=Makefile.${EXT}

INSTALLATION_DIRS=	sbin

do-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/libexec/xmail
.for bin in XMail XMCrypt CtrlClnt MkUsers
	${INSTALL_PROGRAM} ${WRKSRC}/${bin} ${DESTDIR}${PREFIX}/libexec/xmail/${bin}
.endfor
.undef bin
	${INSTALL_SCRIPT} ${WRKSRC}/sendmail    ${DESTDIR}${PREFIX}/sbin/sendmail.xmail
	${INSTALL_SCRIPT} ${WRKSRC}/sendmail.sh ${DESTDIR}${PREFIX}/sbin/sendmail.xmail.sh
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/xmail
.for doc in Readme.txt Readme.html
	${INSTALL_DATA} ${WRKSRC}/docs/${doc} ${DESTDIR}${PREFIX}/share/doc/xmail/${doc}
.endfor
.undef doc

.include "../../mk/bsd.pkg.mk"
