/*****************************************************
 * @file   Movie.c                                   *
 * @author Methodios Zacharioudakis csd4384          *
 *                                                   *
 * @brief Implementation for Movie.h 				 *
 * Project: Winter 2023						         *
 *****************************************************/
#include "Movie.h"

/**
 * @brief Creates a new user.
 * Creates a new user with userID as its identification.
 *
 * @param userID The new user's identification
 *
 * @return 1 on success
 *         0 on failure
 */

 int register_user(int userID){
	int key;
	key=hash_function(userID);
	user_t *newuser = (user_t*)malloc(sizeof(user_t));
	if(user_hashtable_p[key]==NULL){
		newuser->history=NULL;
		newuser->next=NULL;
		newuser->userID=userID;
		user_hashtable_p[key] = newuser; 
		return 1;
	}
	else{
		newuser->history=NULL;
		newuser->next=user_hashtable_p[key];
		newuser->userID=userID;
		user_hashtable_p[key]=newuser;
		return 1;
	} 
	return 0;
 }
 
/**
 * @brief Deletes a user.
 * Deletes a user with userID from the system, along with users' history tree.
 *
 * @param userID The new user's identification
 *
 * @return 1 on success
 *         0 on failure
 */

 int unregister_user(int userID){
	int key;
	key=hash_function(userID);
	if(user_hashtable_p[key]->userID==userID){
		/*Delete history*/
		user_hashtable_p[key]=user_hashtable_p[key]->next;
		return 1;
	}
	else{
		user_t *deluser = user_hashtable_p[key], *preuser = user_hashtable_p[key];
		while(deluser!=NULL){
			if(deluser->userID==userID){
				/*Delete History*/
				preuser->next=deluser->next;
				free(deluser);
				return 1;
			}
			else{
				preuser=deluser;
				deluser=deluser->next;
			}
		}
	}
	return 0;
 }
 
 /**
 * @brief Add new movie to new release binary tree.
 * Create a node movie and insert it in 'new release' binary tree.
 *
 * @param movieID The new movie identifier
 * @param category The category of the movie
 * @param year The year movie released
 *
 * @return 1 on success
 *         0 on failure
 */

 int add_new_movie(int movieID, int category, int year){
	 return 1;
 }
 
 /**
 * @brief Distribute the movies from new release binary tree to the array of categories.
 *
 * @return 0 on success
 *         1 on failure
 */

 int distribute_movies(void){
	 return 1;
 }
 
 /**
 * @brief User rates the movie with identification movieID with score
 *
 * @param userID The identifier of the user
 * @param category The Category of the movie
 * @param movieID The identifier of the movie
 * @param score The score that user rates the movie with id movieID
 *
 * @return 1 on success
 *         0 on failure
 */

 int watch_movie(int userID,int category, int movieID, int score){
	 return 1;
 }
 
/**
 * @brief Identify the best rating score movie and cluster all the movies of a category.
 *
 * @param userID The identifier of the user
 * @param score The minimum score of a movie
 *
 * @return 1 on success
 *         0 on failure
 */

 int filter_movies(int userID, int score){
	 return 1;
 }
 
/**
 * @brief Find movies from categories withn median_score >= score t
 *
 * @param userID The identifier of the user
 * @param category Array with the categories to search.
 * @param score The minimum score the movies we want to have
 *
 * @return 1 on success
 *         0 on failure
 */

 int user_stats(int userID){
	 return 1;
 }
 
/**
 * @brief Search for a movie with identification movieID in a specific category.
 *
 * @param movieID The identifier of the movie
 * @param category The category of the movie
 *
 * @return 1 on success
 *         0 on failure
 */

 int search_movie(int movieID, int category){
	 return 1;
 }
 
 /**
 * @brief Prints the movies in movies categories array.
 * @return 1 on success
 *         0 on failure
 */

 int print_movies(void){
	 return 1;
 }
 
  /**
 * @brief Prints the users hashtable.
 * @return 1 on success
 *         0 on failure
 */

 int print_users(void){
	int i;
	user_t **rep1;
	user_t *rep2;
	userMovie_t *temp;
	rep1=user_hashtable_p;
	for(i=0;i<hashtable_size;i++){
		printf("Chain <%d> of Users:\n",i);
		rep2=rep1[i];
		while(rep2!=NULL){
			printf("\t<%d>\n",rep2->userID);
			printf("\tHistory Tree:\n");
			temp=rep2->history;
			while(temp!=NULL){
				printf("\t\t<%d> <%d>\n",temp->movieID,temp->score);
				temp=temp->lc;
			}
			rep2=rep2->next;
		}	
	}
	
	
	return 1;
 }
 
 int hash_function(int userID){
	int i=0,p=primes_g[0];
	while(i<170&&p<max_id){
		p=primes_g[i];
		i++;
	}
	return (userID%p)%hashtable_size;
}
