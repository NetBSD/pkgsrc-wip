# $NetBSD: Makefile,v 1.2 2010/11/22 21:01:51 ryo-on Exp $
#

DISTNAME=	evernote-mode-0_14
PKGNAME=	${DISTNAME:S/_/./}
CATEGORIES=	editors net
MASTER_SITES=	http://emacs-evernote-mode.googlecode.com/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://code.google.com/p/emacs-evernote-mode/
COMMENT=	Refer and edit Evernote notes directly from Emacs
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

DOCSDIR=		${PREFIX}/share/doc/${PKGBASE}
INSTALLATION_DIRS=	${DOCSDIR} \
			${EMACS_LISPPREFIX}

WRKSRC=		${WRKDIR}/${DISTNAME}/ruby
RUBY_VERSION_SUPPORTED=	19 #18
USE_RUBY_SETUP=	YES

DOCUMENTS=	readme_en.txt \
		readme_ja.txt

SUBST_CLASSES+=		ruby-cmd
SUBST_STAGE.ruby-cmd=	pre-configure
SUBST_FILES.ruby-cmd=	../evernote-mode.el
SUBST_SED.ruby-cmd=	-e 's/ruby/${RUBY_NAME}/'

post-install:
	${INSTALL_DATA} ${WRKSRC}/../evernote-mode.el \
		${DESTDIR}${EMACS_LISPPREFIX}
.for docfile in ${DOCUMENTS}
	${INSTALL_DATA} ${WRKSRC}/../${docfile} \
		${DESTDIR}${DOCSDIR}
.endfor

.include "../../lang/ruby/modules.mk"
.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
