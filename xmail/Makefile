# $NetBSD: Makefile,v 1.6 2005/05/24 10:31:49 rillig Exp $
#

DISTNAME=	xmail-1.18
CATEGORIES=	mail
MASTER_SITES=	http://www.xmailserver.com/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.xmailserver.com/
COMMENT=	SMTP, POP3 and finder server

USE_TOOLS+=	gmake

MAKE_ENV+=	OSTYPE=${OPSYS}

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
.elif ${OPSYS} == "Solaris"
.	if   ${MACHINE_ARCH} == "sparc"
		EXT="sso"
.	elif ${MACHINE_ARCH} == "i86pc"
		EXT="ssx"
.	endif
.endif

MAKEFILE=Makefile.${EXT}

do-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX}/libexec/xmail
.for bin in XMail XMCrypt CtrlClnt MkUsers
	${INSTALL_PROGRAM} ${WRKSRC}/${bin} ${PREFIX}/libexec/xmail/${bin}
.endfor
.undef bin
	${INSTALL_SCRIPT} ${WRKSRC}/sendmail    ${PREFIX}/sbin/sendmail.xmail
	${INSTALL_SCRIPT} ${WRKSRC}/sendmail.sh ${PREFIX}/sbin/sendmail.xmail.sh
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xmail
.for doc in Readme.txt Readme.html
	${INSTALL_DATA} ${WRKSRC}/docs/${doc} ${PREFIX}/share/doc/xmail/${doc}
.endfor
.undef doc

.include "../../mk/bsd.pkg.mk"
