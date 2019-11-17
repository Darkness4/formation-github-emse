# Formation Git (Atlassian-Style) : Plan de formation

## Table des matière

[TOC]

## Presentation

### Git

Git est un logiciel de gestion de versions décentralisé. C'est un logiciel libre créé par Linus Torvalds, auteur du noyau Linux, et distribué selon les termes de la licence publique générale GNU version 2. En 2016, il s’agit du logiciel de gestion de versions le plus populaire qui est utilisé par plus de douze millions de personnes.

\- Wikipedia

### Version Control

 Version Control Systems (VCS) have seen great improvements over the past few decades and some are better than others. VCS are sometimes known as SCM (Source Code Management) tools or RCS (Revision Control System). One of the most popular VCS tools in use today is called Git. Git is a *Distributed* VCS, a category known as DVCS, more on that later. [...] The primary benefits you should expect from version control are as follows. 

1. A complete long-term change history of every file.
2.  Branching and merging.
3.  Traceability.

\- Atlassian

### Source Code Management

- Faire des commit régulier
- Être toujours à jour via `git pull`
- Faire des notes détaillés via `git commit`
- Faire des Code Review
- Faire des branches
- Se mettre d'accord sur un workflow

## Git pour les développeurs

### Feature Branch Workflow

One of the biggest advantages of Git is its branching capabilities. Unlike centralized version control systems, Git branches are cheap and easy to merge. This facilitates the feature branch workflow popular with many Git users.

![Feature branch workflow](https://wac-cdn.atlassian.com/dam/jcr:fcad863b-e0da-4a55-92ee-7caf4988e34e/02.svg?cdnVersion=676)

Feature branches **provide an isolated environment for every change to your codebase**. When a developer wants to start working on something—no matter how big or small—they create a new branch. **This ensures that the master branch always contains production-quality code**.

Using feature branches is not only more reliable than directly editing production code, but it also provides **organizational benefits**. They let you **represent development work at the same granularity as the your [agile backlog](https://www.atlassian.com/agile/backlogs)**. For example, you might implement a policy where each [Jira](https://www.atlassian.com/software/jira) ticket is addressed in its own feature branch.

### Distributed Development

In SVN, each developer gets a working copy that points back to a single central repository. Git, however, is a **distributed version control system**. Instead of a working copy, **each developer gets their own local repository, complete with a full history of commits**.

![Distributed development](https://wac-cdn.atlassian.com/dam/jcr:9d51f0ee-5946-4be2-886c-ff040ef8c1a1/03.svg?cdnVersion=676)

Having a full local history makes Git fast, since it means you don’t need a network connection to create commits, inspect previous versions of a file, or perform diffs between commits. 

Distributed development also makes it **easier to scale your engineering team**. If someone breaks the production branch in SVN, other developers can’t check in their changes until it’s fixed. With Git, this kind of blocking doesn’t exist. Everybody can continue going about their business in their own local repositories.

And, similar to feature branches, distributed development creates a **more reliable environment**. Even if a developer obliterates their own repository, they can simply **clone someone else’s and start anew**.

### Pull Requests

Many source code management tools such as [Bitbucket](https://bitbucket.org/) enhance core Git functionality with pull requests. A pull request is a way to **ask another developer to merge one of your branches into their repository**. This not only makes it easier for project leads to keep track of changes, but also lets developers initiate discussions around their work before integrating it with the rest of the codebase.

![Pull requests](https://wac-cdn.atlassian.com/dam/jcr:92c7f92c-cafb-4254-ab40-0b91821d3fd0/04.svg?cdnVersion=676)

Since they’re essentially a comment thread attached to a feature branch, pull requests are **extremely versatile**. When a developer gets stuck with a hard problem, they can **open a pull request to ask for help from the rest of the team**. Alternatively, junior developers can be confident that they aren’t destroying the entire project by treating pull requests as a **formal code review**. 

## Installer, Configurer Git et Github

### Installer Git

#### Linux

Debian-based :

```sh
apt install git
```

Fedora-based :

```sh
yum install git
```

#### OS X

Git for the Mac platform :

> https://git-scm.com/download/mac

[Homebrew](https://brew.sh/) :

```sh
brew install git
```

#### Windows

Git for the Windows platform :

> https://git-scm.com/download/win

[Chocolatey](https://chocolatey.org/) :

```bat
choco install git
```

### Configuration Git et Github

Configurez votre nom :

```sh
git config --global user.name "John Smith"
```

Configurez votre mail (doit être permanent et servira comme <u>signature</u>, et pourra servir comme signature PGP) :

```sh
git config --global user.email "john.smith@example.com"
```

Créez une clé SSH ED25519 :

```sh
$ ssh-keygen -t ed25519
```

```txt
Generating public/private ed25519 key pair.
Enter passphrase (empty for no passphrase): [ENTER]
Enter same passphrase again: [ENTER]
Your identification has been saved in id_ed25519.
Your public key has been saved in id_ed25519.pub.
The key fingerprint is:
SHA256:[SHA256] description
The key's randomart image is:
+--[ED25519 256]--+
[SHAT256 RANDOMART]
+----[SHA256]-----+
```

Exécutez le ssh-agent :

```sh
eval "$(ssh-agent -s)"
```

Ajoutez la clé **publique** sur votre remote :

 ![Settings icon in the user bar](https://help.github.com/assets/images/help/settings/userbar-account-settings.png)  ![Authentication keys](https://help.github.com/assets/images/help/settings/settings-sidebar-ssh-keys.png)  ![SSH Key button](https://help.github.com/assets/images/help/settings/ssh-add-ssh-key.png)  ![The key field](https://help.github.com/assets/images/help/settings/ssh-key-paste.png) 

 ![The Add key button](https://help.github.com/assets/images/help/settings/ssh-add-key.png) 

## Cheat Sheet

- [Github Cheat Sheet](https://github.github.com/training-kit/downloads/github-git-cheat-sheet.pdf)
- [Atlassian Cheat Sheet](https://www.atlassian.com/git/tutorials/atlassian-git-cheatsheet)
- [Git Tower Cheat Sheet](https://www.git-tower.com/blog/git-cheat-sheet/)
- [Gitlab Cheat Sheet](https://about.gitlab.com/images/press/git-cheat-sheet.pdf)
- [Roger Dudler's Cheat Sheet](https://rogerdudler.github.io/git-guide/files/git_cheat_sheet.pdf)

## Getting Started

### Basic Git Flow

 ![img](https://lh3.googleusercontent.com/Woz1fYvBsuOQLzqn-M8hzjWlZg51fWdukFKQzLfOdQ1yPN95RrlD0E2cs0jn7rrC4b0_FBRDEnZysjzrVQIwE483Ylp_YnU2YztFxghbNL1uECGR7dYPaxrzErWHGmISxr_-ZKK4j2E) 

### Glossaire

#### working tree / working directory / workspace

​	The tree of actual checked out files. The working tree normally contains the **contents of the [HEAD](https://git-scm.com/docs/gitglossary#def_HEAD) commit’s tree, plus any local changes that you have made but not yet committed**.

#### index / staging area

​	A collection of files with stat information, whose contents are stored as objects. The index is a **stored version of your [working tree](https://git-scm.com/docs/gitglossary#def_working_tree)**. Truth be told, it can also contain a second, and even a third version of a working tree, which are used when [merging](https://git-scm.com/docs/gitglossary#def_merge).

#### (local) repository

​	A collection of [refs](https://git-scm.com/docs/gitglossary#def_ref) together with an [object database](https://git-scm.com/docs/gitglossary#def_object_database) containing all objects which are [reachable](https://git-scm.com/docs/gitglossary#def_reachable) from the refs, possibly accompanied by meta data from one or more [porcelains](https://git-scm.com/docs/gitglossary#def_porcelain). A repository can share an object database with other repositories via [alternates mechanism](https://git-scm.com/docs/gitglossary#def_alternate_object_database).

#### remote repository

​	A [repository](https://git-scm.com/docs/gitglossary#def_repository) which is used to **track the same project but resides somewhere else**. To communicate with remotes, see [fetch](https://git-scm.com/docs/gitglossary#def_fetch) or [push](https://git-scm.com/docs/gitglossary#def_push).

#### origin

​	The **default upstream [repository](https://git-scm.com/docs/gitglossary#def_repository)**. Most projects have at least one upstream project which they track. By default *origin* is used for that purpose. New upstream updates will be fetched into [remote-tracking branches](https://git-scm.com/docs/gitglossary#def_remote_tracking_branch) named origin/name-of-upstream-branch, which you can see using `git branch -r`.

#### commit

​	As a noun: **A single point in the Git history**; the entire history of a project is represented as a set of interrelated commits. The word "commit" is often used by Git in the same places other revision control systems use the words "revision" or "version". Also used as a short hand for [commit object](https://git-scm.com/docs/gitglossary#def_commit_object).

​	As a verb: The action of **storing a new snapshot of the project’s state in the Git history**, by creating a new commit representing the current state of the [index](https://git-scm.com/docs/gitglossary#def_index) and advancing [HEAD](https://git-scm.com/docs/gitglossary#def_HEAD) to point at the new commit.

### Cas réel - Créer un projet sur Github

 ![Drop-down with option to create a new repository](https://help.github.com/assets/images/help/repository/repo-create.png)  ![Field for entering a repository name](https://help.github.com/assets/images/help/repository/create-repository-name.png)  ![Field for entering a repository description](https://help.github.com/assets/images/help/repository/create-repository-desc.png)  ![Radio buttons to select private or public status](https://help.github.com/assets/images/help/repository/create-repository-public-private.png) 

**Pas de README.**

**Create repository**.

### Initialiser un repository git

Initialise un [bare repository](https://git-scm.com/docs/gitglossary#Documentation/gitglossary.txt-aiddefbarerepositoryabarerepository).

```sh
git init
```

### Faire un commit

Ajouter un fichier/dossier dans le staging area.

```sh
git add exemple.png
git add . # Ajoute le dossier actuel
```

Commit :

```sh
git commit
git commit -m <message>
```

### Lier le remote au local repository

```sh
git remote add origin git@github.com:auteur/depot.git
```

### Synchroniser le remote origin

```sh
git push
```

## Travail d'équipe

### Cloner un repository Github

```sh
git clone git@github.com:auteur/depot.git
```

### Kit de survie

#### Voir l'état du working tree

 ```sh
git status
 ```

#### Afficher l'historique des commits

```sh
git log
```

#### Stocker les changements dans un repository "caché"

Sauvegarde :

```sh
git stash
```

Lister les sauvegardes :

```sh
git stash list
```

Charger une sauvegarde :

```sh
git stash apply [<stash>]
```

Supprimer une sauvegarde :

```sh
git stash pop [<stash>]
```

#### git commit, en précision

```sh
git commit
git commit -a  # Commit tous les changements des fichiers suivis
git commit -m <message>
git commit --amend  # Refaire le dernier commit
git commit -s/--signoff  # Signer avec l'email
git commit -S/--gpg-sign[=<keyid>]  # Signer avec une clé GPG
```

#### Observer les différences entre les versions/fichiers

```sh
git diff
```

Conseil : Utilisez un bon IDE ([VSCode](https://code.visualstudio.com/), [Atom](https://atom.io/), ...) ou un bon Git GUI ([GitKraken](https://www.gitkraken.com/), [Github Desktop](https://desktop.github.com/), ...)

#### Cacher des secrets (ignorer des fichiers/dossiers au git add)

Créez un fichier .gitignore et écrivez des patterns pour cacher :

```sh
*/dossier  # Tout ce qui est avant dossier
*/fichier.*  # Tous les fichiers qui commence par "fichier"
*/dossier/**  # Tous les dossiers et sous-dossiers
!/fichier.ext  # Sauf fichier.ext
```

### Gitflow Workflow

 ![Git flow workflow - Hotfix Branches](https://wac-cdn.atlassian.com/dam/jcr:61ccc620-5249-4338-be66-94d563f2843c/05%20(2).svg?cdnVersion=676) 



- **master** : État du code source prêt pour la production.
- **develop** : Derniers changements de développement livrés ou aussi appelé branche d'intégration.
- **feature/???** : Fonctionnalité.
- **release/???** : Branche pre-déploiment.
- **hotfix/???** : Litéralement, fix rapide.

### Application : Cas réel

#### Faire des branches

```sh
git branch develop
git checkout develop
```

ou

```sh
git checkout -b develop
```

#### Publier les branches

```sh
git push -u origin develop
```

#### Mettre à jour les informations du remote origin

```sh
git fetch
```

#### Changer de branche

```sh
git checkout develop
```

#### Faire une fonctionnalité et la publier

```sh
git checkout -b feature/my_feature
[work.]
git add .
git commit -m "My feature init"
git push -u origin feature/my_feature
```

#### Mettre à jour les informations du remote origin et merge origin vers local

Assurez-vous d'être sur develop :

```sh
git checkout develop
```

Maintenant, faites merge master:

```sh
git fetch  # Mettre à jour au cas où
git merge origin/develop
```

ou

```sh
git pull
```

#### Merge develop vers feature/my_feature

```sh
git checkout feature/my_feature
git merge develop
git push  # Publiez (ou pas)
```

#### Déployer, de manière Agile, une branche feature vers develop

Aller sur Github et demandez un Pull Request.

#### Merge, de manière Agile, une branche feature vers develop

 ![click-squash-and-merge-button](https://help.github.com/assets/images/help/pull_requests/select-squash-and-merge-from-drop-down-menu.png) 

#### Fixer des merge conflicts

A la main, choisir :

 ![view merge conflict example with conflict markers](https://help.github.com/assets/images/help/pull_requests/view-merge-conflict-with-markers.png) 

Sinon, un bon IDE ([VSCode](https://code.visualstudio.com/), [Atom](https://atom.io/), ...) ou un bon Git GUI ([GitKraken](https://www.gitkraken.com/), [Github Desktop](https://desktop.github.com/), ...).

#### Merge, de manière Agile, une branche develop vers release

 ![merge-pull-request-button](https://help.github.com/assets/images/help/pull_requests/pullrequest-mergebutton.png) 

## Googlez les bases du DevOps en 5 secondes

 ![img](https://miro.medium.com/max/1982/1*EBXc9eJ1YRFLtkNI_djaAw.png) 

### WTF is DevOps ?

D'après [AWS Amazon](https://aws.amazon.com/fr/devops/what-is-devops/),

DevOps est une combinaison de **philosophies culturelles**, de **pratiques** et **d'outils** qui **améliore** la capacité d'une entreprise à **livrer des applications et des services à un rythme élevé**. Il permet de faire **évoluer et d’optimiser les produits plus rapidement** que les entreprises utilisant des processus traditionnels de développement de logiciels et de gestion de l’infrastructure. Cette vitesse permet aux entreprises de **mieux servir leurs clients et de gagner en compétitivité**. 

 ![En quoi consiste le DevOps ?](https://d1.awsstatic.com/product-marketing/DevOps/DevOps_feedback-diagram.ff668bfc299abada00b2dcbdc9ce2389bd3dce3f.png) 

Dans un modèle DevOps, **les équipes de développement et d'opérations ne sont plus isolées**. Il arrive qu'elles soient **fusionnées en une seule et même équipe**. Les ingénieurs qui la composent travaillent alors sur tout le cycle de vie d'une application, de la création à l’exploitation, en passant par les tests et le déploiement, et développent toute une gamme de compétences liées à différentes fonctions.

Dans certains modèles DevOps, les équipes **d'assurance qualité** et de **sécurité** peuvent également s'intégrer étroitement au développement et aux opérations, ainsi qu’à l’ensemble du cycle de vie des applications. Lorsque la sécurité est au cœur de l’activité d’une équipe DevOps, on parle parfois de **DevSecOps**.

Ces équipes utilisent des pratiques pour automatiser des processus qui étaient autrefois manuels et lents. Elles exploitent une **pile technologique et des outils** qui les aident à faire fonctionner et à faire évoluer les applications de façon rapide et fiable. Ces outils aident également les ingénieurs à **accomplir de façon autonome des tâches** (par exemple, le déploiement de code ou la mise en service d'infrastructure) qui nécessiteraient normalement l'aide d'autres équipes, **ce qui augmente encore davantage la productivité de l’équipe d’ingénieurs.**

### [Culture](https://www.atlassian.com/team-playbook/examples/devops-culture)

### Automation : [Enable on demand creation of dev, test, and production environments](https://caylent.com/devops-handbook-part-3-continuous-delivery)

- **Export d'environnement virtualisé** : [Vagrant](https://www.vagrantup.com/), [VMware](https://www.vmware.com/) Image, ...
- **[Preboot Execution Environment](https://en.wikipedia.org/wiki/Preboot_Execution_Environment)** : [Debian PXEBootInstall](https://wiki.debian.org/PXEBootInstall), ...
- **"[Infrastructure as Code](https://en.wikipedia.org/wiki/Infrastructure_as_code)" (IaC) configuration management** : [Puppet](https://puppet.com/), [Ansible](https://www.ansible.com/), [Chef](https://www.chef.io/), ...
- **Configuration d'OS automatisée** : [Debian preseed](https://www.debian.org/releases/stable/amd64/apb.en.html), [Red Hat Kickstart](https://access.redhat.com/documentation/en-us/red_hat_enterprise_linux/8/html/performing_an_advanced_rhel_installation/performing_an_automated_installation_using_kickstart), ...
- **Approvisionnement automatisé des VM ou des Containers** : [Vagrant](https://www.vagrantup.com/), [Docker](https://www.docker.com/), ..
- **Mise en place automatisée un environnement sur un cloud public** : [Google App Engine](https://cloud.google.com/appengine/), [Microsoft Azure](https://azure.microsoft.com/en-us/), [Amazon Web Services](https://aws.amazon.com/), ...
- **Mise en place automatisée un environnement sur un cloud privé** : Do it yourself !
- **Mise en place automatisée un environnement sur un "Platform as a Service" (PaaS)** : [OpenStack](https://www.openstack.org/), [CloudFoundry](https://www.cloudfoundry.org/), ...

### Lean : [Create our single repository of truth for the entire system](https://caylent.com/devops-handbook-part-3-continuous-delivery)

- **[Version Control System](https://git-scm.com/book/en/v2/Getting-Started-About-Version-Control)** : [Git](https://git-scm.com/), [SVN](https://subversion.apache.org/), [CVS](https://www.nongnu.org/cvs/), [Bazaar](https://bazaar.canonical.com/en/), [Mercurial](https://www.mercurial-scm.org/)
- **Git hosting** : [Github](https://github.com/), [Gitlab](https://gitlab.com/), [Bitbucket](https://bitbucket.org/product), [SourceForge](https://sourceforge.net/), [Launchpad](https://launchpad.net/), DIY, ...
- **[Continuous Integration and Continuous Delivery (CI/CD)](https://www.docker.com/solutions/cicd)** : [Github Actions](https://github.com/features/actions), [Gitlab CI](https://about.gitlab.com/product/continuous-integration/), [Travis CI](https://travis-ci.org), [Appveyor](https://www.appveyor.com/), [Google Cloud Build](https://cloud.google.com/cloud-build/)...
  - Build
    - Make
    - CMake
    - Ninja
    - Gradle
  - Test
    - Unit Tests (UT)
    - Integration Tests (IT)
    - GUI Tests
    - Static Application Security Testing (SAST)
    - Dynamic Application Security Testing (DAST)
    - Interactive Application Security Testing (IAST)
    - Exploratory Testing (manual)
    - User Acceptance Testing (UAT) (manual)
    - Production Testing (manual)
  - Deploy (**FULL AUTOMATED**)
- **Microservices** : [AWS Lambda](https://aws.amazon.com/fr/lambda/), [Google App Engine](https://cloud.google.com/appengine/docs/standard/python/microservices-on-app-engine) et pratiquement tout ce qu'il y a dans Automation.

### Monitor & Communication

- **Atlassian & Jira** (Project, Issue Tracking, Agile Planning, Management, Service Desk, Customer Service, Incident Management, Incident Communication)
- **Github** (Project, Issue Tracking, Agile Planning, Kanban, Milestones)
- Et plein d'autres...