# $NetBSD: Makefile,v 1.4 2012/10/05 11:31:52 asau Exp $
#

DISTNAME=	plod-1.9
CATEGORIES=	sysutils
MASTER_SITES=	http://www.far2wise.net/plod/ \
		http://jfranz.users.bsdprojects.net/distfiles/

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://www.far2wise.net/plod/
COMMENT=	System administration journaling tool

REPLACE_PERL+=	plod

DOCDIR=	${PREFIX}/share/doc/${DISTNAME:S/-1.9//}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${DOCDIR}

do-build:
	cd ${WRKSRC} && gzip -d plod.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/plod ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/plod.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/plod.el ${DESTDIR}${EMACS_LISPPREFIX}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}

#.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
