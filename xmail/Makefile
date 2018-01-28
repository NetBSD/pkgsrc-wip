# $NetBSD: Makefile,v 1.13 2012/12/09 21:20:33 othyro Exp $
#

DISTNAME=	xmail-1.27
CATEGORIES=	mail
MASTER_SITES=	http://www.xmailserver.com/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.xmailserver.com/
COMMENT=	SMTP, POP3 and finder server
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

MAKE_ENV+=	OSTYPE=${OPSYS}

.include "../../mk/bsd.prefs.mk"

EXT=bsd # Default one :)
.if ${OPSYS} == "Linux"
.  if   ${MACHINE_ARCH} == "i86pc"
		EXT="lnx"
.  elif ${MACHINE_ARCH} == "sparc"
		EXT="slx"
.  elif ${MACHINE_ARCH} == "ppc"
		EXT="plx"
.  endif
.elif ${OPSYS} == "SunOS"
.  if   ${MACHINE_ARCH} == "sparc"
		EXT="sso"
.  elif ${MACHINE_ARCH} == "i86pc"
		EXT="ssx"
.  endif
.endif

MAKE_FILE=	Makefile.${EXT}

INSTALLATION_DIRS+=	libexec/${PKGBASE} sbin share/doc/${PKGBASE}

do-install:
.for bin in XMail XMCrypt CtrlClnt MkUsers
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${bin} ${DESTDIR}${PREFIX}/libexec/xmail/${bin}
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/bin/sendmail    ${DESTDIR}${PREFIX}/sbin/sendmail.xmail
	${INSTALL_SCRIPT} ${WRKSRC}/sendmail.sh ${DESTDIR}${PREFIX}/sbin/sendmail.xmail.sh
.for doc in Readme.txt Readme.html
	${INSTALL_DATA} ${WRKSRC}/docs/${doc} ${DESTDIR}${PREFIX}/share/doc/xmail/${doc}
.endfor

.include "../../mk/bsd.pkg.mk"
